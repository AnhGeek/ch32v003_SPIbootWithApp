/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/22
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
/*
 *@Note
 *GPIO routine:
 *PD0 push-pull output.
 *
*/

#include "debug.h"
#include "spiflash.h"
#include "iap.h"
#include <stddef.h>

void *memset(void *dest, int value, size_t len)
{
    unsigned char *ptr = dest;
    while (len--)
        *ptr++ = (unsigned char)value;
    return dest;
}

/* Global define */

/* Global Variable */

/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIOA.0
 *
 * @return  none
 */
void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {GPIO_Pin_0, GPIO_Speed_30MHz, GPIO_Mode_Out_PP};

    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

}

/*********************************************************************
 * @fn      GoToIAP
 *
 * @brief   Go to IAP
 *
 * @return  none
 */
void GoToIAP(void)
{
    RCC_ClearFlag();
    SystemReset_StartMode(Start_Mode_BOOT);
    NVIC_SystemReset();
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    u8 i = 0;
    u8 led = 0;
    //u8 led1 = 12;
    u8 isNewFirmware = 0;
    uint16_t app_length = 0;
    u8 flasData[256] = {0};
    u8 TxData[18] = {0x02, 0x02, 0x03, 0x04};
    u8 checksumCurrent = 0x00;
    u8 checksumRequest = 0x00;
    flash_info_t flash_info = {0};
    flash_info_t flash_info_test = {0};
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_SPI1, ENABLE );
    Delay_Init();
    GPIO_Toggle_INIT();
    SPI_FullDuplex_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
    SDI_Printf_Enable();
#else
    USART_Printf_Init(115200);
#endif
    printf("\r\n\r\n==============================\r\n");
    printf("\r\nVersion originqq.\r\n");
    printf("\r\nSystemClk:%d\r\n", SystemCoreClock);
    printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("Flash_used = 0x%08x (%u bytes)\r\n", (unsigned)GetLengthFlashMCU(), (unsigned)GetLengthFlashMCU());
    
    
    // SPIF_erase(); 
    SPIF_3B_erase_page(1);
    SPIF_read(NORMAL_FLASH, 0 ,&isNewFirmware, 1);
    printf( "\r\nisNewFirmware: 0x%02X ", isNewFirmware);
    // if(isNewFirmware == 0xFF)
    // {
    //     WriteFlashMCU();
    //     isNewFirmware = 0xFA;
    //     SPIF_write(NORMAL_FLASH, 0 ,&isNewFirmware, 1);
    // }
    // SPIF_read(NORMAL_FLASH, 4 ,&checksumCurrent, 1);
    // flash_info.isNewFlash = 0xaa;
    // flash_info.chkBackup = 0x01;
    // flash_info.lenBackup = 0x02;
    // flash_info.chkNew = 0x03;
    // flash_info.lenNew = 0x04;
    SPIF_write(SECURITY_AREA, 0x1000, (uint8_t*)&flash_info, sizeof(flash_info_t));
    SPIF_read(SECURITY_AREA, 0x1000, (uint8_t*)&flash_info_test, sizeof(flash_info_t));
    
    SPIF_read(SECURITY_AREA, 0x1000 ,flasData, 256);
    printf("\r\nSecurity Block 0: ");
    for (int i = 0; i < 256; i++) {
        u8 data = 0;
        data = *((u8*)flasData+i);
        printf("0x%02X ", data);  // Use %d for int
    }
    
    SPIF_read(NORMAL_FLASH, 0 ,flasData, 256);
    printf("\r\nZero Block: ");
    for (int i = 0; i < 256; i++) {
        u8 data = 0;
        data = *((u8*)flasData+i);
        printf("0x%02X ", data);  // Use %d for int
    }

    SPIF_read(NORMAL_FLASH, 256 ,flasData, 256);
    printf("\r\nFirst Block: ");
    for (int i = 0; i < 256; i++) {
        u8 data = 0;
        data = *((u8*)flasData+i);
        printf("0x%02X ", data);  // Use %d for int
    }

    SPIF_read(NORMAL_FLASH, 256*23 ,flasData, 256);
    printf("\r\n\r\nLast Block: ");
    for (int i = 0; i < 256; i++) {
        u8 data = 0;
        data = *((u8*)flasData+i);
        printf("0x%02X ", data);  // Use %d for int
    }

    while(1)
    {
        Delay_Ms(100);
        
        //printf("\r\nCounting: %d", i);
        GPIO_WriteBit(GPIOC, GPIO_Pin_0, (led == 0) ? (led = Bit_SET) : (led = Bit_RESET));
        GPIO_WriteBit(GPIOD, GPIO_Pin_2, led);
        
        if( SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_TXE ) != RESET )
        {
           
            
            
            i++;
            
        }
        
        if(i == 18) i = 0;
    }
}
