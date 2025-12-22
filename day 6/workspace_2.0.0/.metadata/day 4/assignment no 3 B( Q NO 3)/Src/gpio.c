/*
 * gpio.c
 *
 *  Created on: 17-Dec-2025
 *      Author: Admin
 */
#include "gpio.h"

void GPIO_Init(void)
{
    /* Enable GPIOA and GPIOD clocks */
    RCC_AHB1ENR |= (1 << 0);   // GPIOA
    RCC_AHB1ENR |= (1 << 3);   // GPIOD

    /* PA0 as input */
    GPIOA_MODER &= ~(3 << (0 * 2));

    /* PD12 & PD15 as output */
    GPIOD_MODER &= ~(3 << (GREEN_LED * 2));
    GPIOD_MODER |=  (1 << (GREEN_LED * 2));

    GPIOD_MODER &= ~(3 << (BLUE_LED * 2));
    GPIOD_MODER |=  (1 << (BLUE_LED * 2));
}

uint8_t GPIO_ReadSwitch(void)
{
    return (GPIOA_IDR & (1 << 0)) ? 1 : 0;
}

void LED_GreenOn(void)
{
    GPIOD_ODR |=  (1 << GREEN_LED);
    GPIOD_ODR &= ~(1 << BLUE_LED);
}

void LED_BlueOn(void)
{
    GPIOD_ODR |=  (1 << BLUE_LED);
    GPIOD_ODR &= ~(1 << GREEN_LED);
}

void LED_AllOff(void)
{
    GPIOD_ODR &= ~(1 << GREEN_LED);
    GPIOD_ODR &= ~(1 << BLUE_LED);
}


