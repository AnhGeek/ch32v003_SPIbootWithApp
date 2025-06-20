/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.1
 * Date               : 2025/01/09
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
/*
 * IAP routine: this routine support only UART mode,
 * and you can choose the command method or the IO method to jump to the APP .
 * Key  parameters: CalAddr - address in flash (same in APP), note that this address needs to be unused.
 *                  CheckNum - The value of 'CalAddr' that needs to be modified.
 * Tips :the routine need IAP software version 1.50.
 */
/*
 * note: The serial port baud rate values and BRR register values for different clock master frequencies are as follows.
 *              baud rate = 460800 ------- USARTx->BRR = 0X34 ------- System clock = 24MHz
 *              baud rate = 460800 ------- USARTx->BRR = 0X68 ------- System clock = 48MHz
 *              ...
 *       Set the value of the BRR register at different clock frequencies in order to select
 *       the desired serial communication frequency.
 */
#include "debug.h"
#include "string.h"
#include "iap.h"

extern u8 End_Flag;
#define UPGRADE_MODE_COMMAND   0
#define UPGRADE_MODE_IO        1

#define UPGRADE_MODE   UPGRADE_MODE_COMMAND

/*********************************************************************
 * @fn      IAP_2_APP
 *
 * @brief   IAP_2_APP program.
 *
 * @return  none
 */
void IAP_2_APP(void)
{
    RCC_ClearFlag();
    SystemReset_StartMode(Start_Mode_USER);
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
    u8 iap2app_counter = 0;
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOD| RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOC;/* Enable GPIOD,USART1, GPIOC  clock */
    USART1_CFG();
    Delay_Init();
    while(1){
        UART1_SendData(0x42);
        UART1_SendData(0x6F);
        UART1_SendData(0x6F);
        UART1_SendData(0x74);
        UART1_SendData(0x0D);
        UART1_SendData(0x0A);
        Delay_Ms(500);
        iap2app_counter++;
        if (iap2app_counter == 10) IAP_2_APP();
    }

    
}
