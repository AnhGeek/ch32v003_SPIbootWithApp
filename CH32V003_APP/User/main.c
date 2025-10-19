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

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
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
    uint8_t data1 = 0, data2 = 0;
    u8 flasData[100] = {0};
    u8 TxData[18] = {0x01, 0x02, 0x03, 0x04};
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_SPI1, ENABLE );
    Delay_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
    SDI_Printf_Enable();
#else
    USART_Printf_Init(115200);
#endif
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("GPIO Toggle TEST\r\n");
    
    GPIO_Toggle_INIT();
    SPI_FullDuplex_Init();
    // SPIF_erase();
    // SPIF_write(0,TxData, 4);

    while(1)
    {
        Delay_Ms(100);
        printf("\r\nCounting: %d", i);
        GPIO_WriteBit(GPIOC, GPIO_Pin_0, (led == 0) ? (led = Bit_SET) : (led = Bit_RESET));
        GPIO_WriteBit(GPIOD, GPIO_Pin_2, led);
        
        if( SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_TXE ) != RESET )
        {
            
           
            data1 = SPIF_read(0, (u8*)flasData, 32);
            printf("\r\nArray contents: ");
            for (int i = 0; i < 32; i++) {
                printf("0x%02X ", *((u8*)flasData+i));  // Use %d for int
            }
            printf("\n");
            
            
            i++;
        }
        
        if(i == 18) i = 0;
    }
}
