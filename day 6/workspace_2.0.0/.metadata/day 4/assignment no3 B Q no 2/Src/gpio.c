/*
 * gpio.c
 *
 *  Created on: 17-Dec-2025
 *      Author: Admin
 */
#include "gpio.h"

void GPIO_Init(void)
{
    /* Enable clocks for GPIOA and GPIOD */
    RCC_AHB1ENR |= (1 << 0);   // GPIOA
    RCC_AHB1ENR |= (1 << 3);   // GPIOD

    /* PA0 as input (00) */
    GPIOA_MODER &= ~(3 << (0 * 2));

    /* PD14 as output (01) */
    GPIOD_MODER &= ~(3 << (14 * 2));
    GPIOD_MODER |=  (1 << (14 * 2));
}

uint8_t GPIO_ReadSwitch(void)
{
    return (GPIOA_IDR & (1 << 0)) ? 1 : 0;
}

void GPIO_ToggleRedLED(void)
{
    GPIOD_ODR ^= (1 << 14);
}


