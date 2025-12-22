/*
 * gpio.h
 *
 *  Created on: 17-Dec-2025
 *      Author: Admin
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/* Base addresses */
#define PERIPH_BASE        0x40000000UL
#define AHB1PERIPH_BASE    (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE           (AHB1PERIPH_BASE + 0x3800UL)
#define GPIOA_BASE         (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOD_BASE         (AHB1PERIPH_BASE + 0x0C00UL)

/* RCC register */
#define RCC_AHB1ENR        (*(volatile uint32_t *)(RCC_BASE + 0x30))

/* GPIO registers */
#define GPIOA_MODER        (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_IDR          (*(volatile uint32_t *)(GPIOA_BASE + 0x10))

#define GPIOD_MODER        (*(volatile uint32_t *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR          (*(volatile uint32_t *)(GPIOD_BASE + 0x14))

/* Function prototypes */
void GPIO_Init(void);
uint8_t GPIO_ReadSwitch(void);
void GPIO_ToggleRedLED(void);

#endif
