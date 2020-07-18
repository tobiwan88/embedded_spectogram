#include <stdint.h>
#define STM32F429xx
#include "stm32f4xx.h"
#include "stm32f4xx_ll_rcc.h"
#include <stm32f4xx_ll_gpio.h>
int main()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
    volatile auto i = 10000;
    while (i--)
        ;
    LL_GPIO_SetPinMode(GPIOG, LL_GPIO_PIN_13, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinMode(GPIOG, LL_GPIO_PIN_14, LL_GPIO_MODE_OUTPUT);

    while(1)
    {
        volatile auto i = 100000;
        while(i--);
        LL_GPIO_TogglePin(GPIOG,LL_GPIO_PIN_13);
        LL_GPIO_TogglePin(GPIOG, LL_GPIO_PIN_14);
    }

    return -1;
}