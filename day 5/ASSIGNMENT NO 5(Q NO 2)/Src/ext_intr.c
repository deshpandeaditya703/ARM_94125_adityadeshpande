/*
 * ext_intr.c
 *
 *  Created on: Dec 18, 2025
 *      Author: kiran_z6dopa8
 */


#include"my_led.h"
volatile int exti0_flag=0;
void extint_init(void)
{
    // 1. Enable AHB1 clock for GPIOA
    //    Without enabling the clock, GPIOA registers cannot be accessed
    RCC->AHB1ENR |= BV(0);

    // 2. Configure PA0 as input mode
    //    MODER0[1:0] = 00 → Input mode
    GPIOA->MODER &= ~(BV(0) | BV(1));

    // 3. Disable internal pull-up / pull-down on PA0
    //    External pull-down is already present on the board (USER button)
    GPIOA->PUPDR &= ~(BV(0) | BV(1));

    // 4. Map PA0 to EXTI line 0 using SYSCFG
    //    EXTICR[0] controls EXTI0–EXTI3
    //    Clearing bits selects Port A for EXTI0
    SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));

    // 5. Configure EXTI line 0
    //    Unmask EXTI0 interrupt
    EXTI->IMR |= BV(0);

    //    Enable rising-edge trigger on EXTI0
    //    PA0 goes LOW → HIGH when USER button is pressed
    EXTI->RTSR |= (1<<0);
    EXTI->RTSR  &= ~(1<<0);


    // 6. Enable EXTI0 interrupt in NVIC
    //    Allows the Cortex-M3 core to accept EXTI0 interrupts
    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
	 if (EXTI->PR & (1 << 0))        // Check pending interrupt for EXTI0
	    {
	        EXTI->PR = (1 << 0);        // Clear EXTI0 pending bit (write 1 to clear)
	        exti0_flag = 1;             // Set software flag
	    }
	}

