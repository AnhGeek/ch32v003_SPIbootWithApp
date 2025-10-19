#ifndef __SPI_H
#define __SPI_H

#include <ch32v00x.h>
/* Chip select */
#define FLASH_CS_PIN  GPIO_Pin_0 // PD0



void SPI_FullDuplex_Init();
uint8_t spi_write_read(uint8_t data);
void flash_select();
void flash_deselect();

#define SPIF_CS_enable flash_select
#define SPIF_CS_disable flash_deselect
#define SPIF_send_inst spi_write_read

#endif /* __SPI_H */