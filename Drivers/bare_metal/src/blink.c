#include "blink.h"

void Enable_LED(void){
    //enables gpioA clock
    RCC->AHB1ENR |= 0x01;

    // PA5 mode bits are MODER[11:10]
    // Clear them
    GPIOA->MODER &= ~0xC00;

    // Set 01 = general-purpose output
    GPIOA->MODER |= 0x400;

    // Push-pull: OTYPER bit 5 = 0
    GPIOA->OTYPER &= ~0x20;

    // Low speed: OSPEEDR[11:10] = 00
    GPIOA->OSPEEDR &= ~0xC00;

    // No pull-up / pull-down: PUPDR[11:10] = 00
    GPIOA->PUPDR &= ~0xC00;
}

void LED_HIGH(){
    GPIOA->BSRR = 0x00000020; // Set PA5 HIGH
}

void LED_LOW(){
    GPIOA->BSRR = 0x200000; // Reset PA5 LOW
}