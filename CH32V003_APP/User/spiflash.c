/*
 * spiflash.c
 *
 * Author : Jusepe ITasahobby
 */

#define F_CPU 16000000UL
#include "spiflash.h"

/* Winbound W25Q512JV instruction set */

#define SPIF_INST_READ_RESPONSE             0xAA
#define SPIF_INST_READ_STATUS_1             0x05
#define SPIF_INST_READ_STATUS_2             0x35
#define SPIF_INST_READ_STATUS_3             0x15
#define SPIF_INST_WRITE_STATUS_1            0x01
#define SPIF_INST_WRITE_STATUS_2            0x31
#define SPIF_INST_WRITE_STATUS_3            0x11
#define SPIF_INST_ENABLE_WRITE              0x06
#define SPIF_INST_3B_WRITE                  0x02
#define SPIF_INST_3B_READ                   0x03
#define SPIF_INST_3B_SEC_WRITE              0x42
#define SPIF_INST_3B_SEC_READ               0x48 
#define SPIF_INST_3B_ERASE_SECT             0x20
#define SPIF_INST_3B_ERASE_SEC_RES          0x44
#define SPIF_INST_ERASE_32BLOCK             0x52
#define SPIF_INST_ERASE                     0xC7


/* Winbound W25Q512JV status register */
#define SPIF_STAT_BUSY                      0x01
#define SPIF_STAT_WRITE_ENABLE              0x02

/*
** Winbound specs
** SPIF_SIZE is 67108864, last sector is used temporally on writing operations.
*/
#define SPIF_PAGE_SIZE                      256
#define SPIF_SECTOR_SIZE                    4096
#define SPIF_VIRT_SIZE                      67104768
#define SPIF_SIZE                           67108864

/************************************************************************/
/*                         AUXILIARY FUNCTIONS                          */
/************************************************************************/

/*
** Reads Status Register. May be used at any time, even while a Program,
** Erase or Write Status Register cycle is in progress
*/
uint8_t SPIF_read_status()
{
	uint8_t status;
	SPIF_CS_disable();
	SPIF_CS_enable();

	SPIF_send_inst(SPIF_INST_READ_STATUS_1);
	status = SPIF_send_inst(SPIF_INST_READ_RESPONSE);
	SPIF_CS_disable();
	return status;
}

/*
** Sets WEL bit to 1, keep in mind that Write enable bit is
** automatically reset after completion of the Write Status
** Register, Erase/Program Security Registers, Page Program,
** Sector Erase, Block Erase, Chip Erase among others.
*/
void SPIF_enable_write()
{
	SPIF_CS_disable();
	SPIF_CS_enable();

	SPIF_send_inst(SPIF_INST_ENABLE_WRITE);

	SPIF_CS_disable();

	while (!(SPIF_read_status() & SPIF_STAT_WRITE_ENABLE)) {}

	return;
}

/*
** Auxiliary function to read data from flash and write into the given buffer.
** It has all memory address space available, including the last sector used 
** as temporary storage.
*/
SPIF_RET_t SPIF_uncheck_read(uint8_t security_area, uint32_t address, uint8_t* buff, uint32_t size)
{

	if (address > SPIF_SIZE) return SPIF_ERR_MEM_ADDR_OUTOF_RANGE;
	if (address + size > SPIF_SIZE) return SPIF_ERR_SIZE_OUTOF_RANGE;

	while (SPIF_read_status() & SPIF_STAT_BUSY) {}

	SPIF_CS_disable();
	SPIF_CS_enable();

	SPIF_send_inst(security_area ? SPIF_INST_3B_SEC_READ : SPIF_INST_3B_READ);

	SPIF_send_inst(address >> 16);
	SPIF_send_inst(address >> 8);
	SPIF_send_inst(address);
	if(security_area) SPIF_send_inst(SPIF_INST_READ_RESPONSE);

	for (uint32_t j = 0; j < size; j++)
	{
		buff[j] = SPIF_send_inst(SPIF_INST_READ_RESPONSE);
	}

	SPIF_CS_disable();

	return SPIF_OK;
}

/*
** Auxiliary function to write given buffer to flash. It has all memory address
** space available, including the last sector used as temporary storage.
*/
SPIF_RET_t SPIF_uncheck_write(uint8_t security_area, uint32_t address, uint8_t* buff, uint32_t size)
{
	uint32_t offset = 0;
	uint32_t page_address = 0;
	uint32_t first_page = address - (address % SPIF_PAGE_SIZE);
	uint32_t last_page = ( (address + size - 1) / SPIF_PAGE_SIZE ) * SPIF_PAGE_SIZE;
	int32_t pages_count = (size / SPIF_PAGE_SIZE) - 1;
	uint32_t write_count = 0;

	if (size <= 0 ) return SPIF_ERR_MEM_INVALID_ADDR;
	if (address > SPIF_SIZE) return SPIF_ERR_MEM_ADDR_OUTOF_RANGE;
	if (address + size > SPIF_SIZE) return SPIF_ERR_SIZE_OUTOF_RANGE;

	while (SPIF_read_status() & SPIF_STAT_BUSY) {}

	/* Write first page */

	SPIF_enable_write();

	SPIF_CS_disable();
	SPIF_CS_enable();

	SPIF_send_inst(security_area ? SPIF_INST_3B_SEC_WRITE : SPIF_INST_3B_WRITE);
	SPIF_send_inst(address >> 16);
	SPIF_send_inst(address >> 8);
	SPIF_send_inst(address);


	if ( (address + size) >= (first_page + SPIF_PAGE_SIZE) )
	{
		write_count = first_page + SPIF_PAGE_SIZE - address;
	}
	else
	{
		write_count = size;
	}

	for (uint16_t j = 0; j < write_count; j++)
	{
		SPIF_send_inst(buff[j]);
	}

	SPIF_CS_disable();

	while (SPIF_read_status() & SPIF_STAT_BUSY) {}

	/* Write pages in the middle */

	for (int32_t i = 0; i < pages_count; i++)
	{
		offset = i * SPIF_PAGE_SIZE + write_count;
		page_address = first_page +  SPIF_PAGE_SIZE + (i * SPIF_PAGE_SIZE);
		SPIF_enable_write();

		SPIF_CS_disable();
		SPIF_CS_enable();

		SPIF_send_inst(security_area ? SPIF_INST_3B_SEC_WRITE : SPIF_INST_3B_WRITE);
		SPIF_send_inst(page_address >> 16);
		SPIF_send_inst(page_address >> 8);
		SPIF_send_inst(page_address);


		for (uint16_t j = 0; j < SPIF_PAGE_SIZE; j++)
		{
			SPIF_send_inst(buff[offset + j]);
		}

		SPIF_CS_disable();

		while (SPIF_read_status() & SPIF_STAT_BUSY) {}

	}


	if(last_page && (first_page != last_page) )
	{
		offset = last_page - address;
		write_count = address + size - last_page;

		SPIF_enable_write();

		SPIF_CS_disable();
		SPIF_CS_enable();

		SPIF_send_inst(security_area ? SPIF_INST_3B_SEC_WRITE : SPIF_INST_3B_WRITE);
		SPIF_send_inst(last_page >> 16);
		SPIF_send_inst(last_page >> 8);
		SPIF_send_inst(last_page);

		for (uint16_t j = 0; j < write_count ; j++)
		{
			SPIF_send_inst(buff[offset + j]);
		}
        SPIF_CS_disable();
		while (SPIF_read_status() & SPIF_STAT_BUSY) {}
	}

	return SPIF_OK;
}

/************************************************************************/
/*                          EXPORTED FUNCTIONS                          */
/************************************************************************/

/* Fill the whole flash with 0xFF, it may take some time. */
void SPIF_erase(void)
{
	while ((SPIF_read_status() & SPIF_STAT_BUSY)) {}

	SPIF_enable_write();

	SPIF_CS_disable();
	SPIF_CS_enable();

	SPIF_send_inst(SPIF_INST_ERASE);

	SPIF_CS_disable();

	return;
}

/* Fill the given sector with 0xFF, */
void SPIF_3B_erase_page(uint8_t page)
{
	while (SPIF_read_status() & SPIF_STAT_BUSY) {}

	SPIF_enable_write();

	SPIF_CS_disable();
	SPIF_CS_enable();

	SPIF_send_inst(SPIF_INST_3B_ERASE_SEC_RES);

	SPIF_send_inst(0x00);
	SPIF_send_inst((page << 4) & 0xF0);
	SPIF_send_inst(0x00);


	SPIF_CS_disable();

	return;
}

/* Return page size in bytes. */
uint16_t SPIF_get_page_size(void)
{
	return SPIF_PAGE_SIZE;
}

/* Return sector size in bytes */
uint16_t SPIF_get_sector_size(void)
{
	return SPIF_SECTOR_SIZE;
}

/* Return usable flash size in bytes */
uint32_t SPIF_get_size(void)
{
	return SPIF_VIRT_SIZE;
}

/* Read from flash to buffer up to last sector*/
SPIF_RET_t SPIF_read(uint8_t security_area, uint32_t address, uint8_t* buff, uint32_t size)
{

	if (address > SPIF_VIRT_SIZE )  return SPIF_ERR_MEM_ADDR_OUTOF_RANGE;
	if (address + size > SPIF_VIRT_SIZE ) return SPIF_ERR_SIZE_OUTOF_RANGE;

	return SPIF_uncheck_read(security_area, address, buff, size);
}

/*
** Attempts to write data, if any involved page has no compatible data (writing
** 1's where there is a 0's) then returns SPIF_ERR_INCOMPATIBLE_WRITE. Any previous
** pages that were compatible are writen.
*/
SPIF_RET_t SPIF_write(uint8_t security_area, uint32_t address, uint8_t* buff, uint32_t size)
{
	uint32_t offset = 0;
	uint32_t page_address = 0;
	uint32_t remainder = size % SPIF_PAGE_SIZE;
	uint8_t read_byte = 0;
	uint8_t result = 0;

	/* Check for size errors */
	if (address > SPIF_VIRT_SIZE ) return SPIF_ERR_MEM_ADDR_OUTOF_RANGE;
	if (address + size > SPIF_VIRT_SIZE ) return SPIF_ERR_SIZE_OUTOF_RANGE;

	while (SPIF_read_status() & SPIF_STAT_BUSY) {}

	for (uint32_t i = 0; i < (size / SPIF_PAGE_SIZE); i++)
	{
		offset = i * SPIF_PAGE_SIZE;
		page_address = address + offset;

		/* Check if compatible */
		SPIF_CS_disable();
		SPIF_CS_enable();

		SPIF_send_inst(security_area ? SPIF_INST_3B_SEC_READ : SPIF_INST_3B_READ);
		//SPIF_send_inst(address >> 24);
		SPIF_send_inst(address >> 16);
		SPIF_send_inst(address >> 8);
		SPIF_send_inst(address);

		for (uint32_t j = 0; j < SPIF_PAGE_SIZE; j++)
		{
			read_byte = SPIF_send_inst(SPIF_INST_READ_RESPONSE);
			result = (~buff[offset + j]) | read_byte;
			if( result != 0xFF) return SPIF_ERR_INCOMPATIBLE_WRITE;
		}

		SPIF_CS_disable();

		/* Write page */
		SPIF_fast_write(security_area, page_address, buff+offset, SPIF_PAGE_SIZE);
	}

	if( remainder != 0 )
	{
		offset = size - remainder;
		page_address = address + offset;

		SPIF_CS_disable();
		SPIF_CS_enable();

		SPIF_send_inst(security_area ? SPIF_INST_3B_SEC_READ : SPIF_INST_3B_READ);
		SPIF_send_inst(page_address >> 16);
		SPIF_send_inst(page_address >> 8);
		SPIF_send_inst(page_address);

		for (uint32_t j = 0; j < 1; j++)
		{
			read_byte = SPIF_send_inst(SPIF_INST_READ_RESPONSE);
			result = (~buff[offset + j]) | read_byte;
			if( result != 0xFF) return SPIF_ERR_INCOMPATIBLE_WRITE;
		}

		SPIF_CS_disable();

		SPIF_fast_write(security_area, page_address, buff+offset, remainder);

	}

	return SPIF_OK;
}

/*
** Write without erasing involved sectors. ONLY use when given sectors
** are filled with 0xFF (erased), otherwise the sectors may end up with
** corrupted data.
*/
SPIF_RET_t SPIF_fast_write(uint8_t security_area, uint32_t address, uint8_t* buff, uint32_t size)
{
	if (address > SPIF_VIRT_SIZE ) return SPIF_ERR_MEM_ADDR_OUTOF_RANGE;
	if (address + size > SPIF_VIRT_SIZE ) return SPIF_ERR_SIZE_OUTOF_RANGE;

	return SPIF_uncheck_write(security_area, address, buff, size);
}

/*
** Checks if the data to write is compatible with already stored information,
** otherwise it writes data to an auxiliary sector and overwrites the whole
** sector.
*/
SPIF_RET_t SPIF_force_write(uint8_t security_area, uint32_t address, uint8_t* buff, uint32_t size)
{
	/*
	** Write instruction can only write 0s so we need to read the involved
	** sectors, which is the smallest unit we can erase. Afterwards we
	** write the previously stored data updated with the new one.
	*/
	SPIF_RET_t ret = SPIF_write(security_area, address, buff, size);
	if (ret == SPIF_ERR_INCOMPATIBLE_WRITE)
	{
		return SPIF_slow_write(security_area, address, buff, size);
	}

	return ret;
}

