#include "stm32f446xx.h"

void delay(long delay)
{
	while(delay--);
}

int main(void)
{
	RCC->CR = RCC->CR | (1<<0);
	
	RCC->AHB1ENR = RCC->AHB1ENR | (1<<0);
	
	GPIOA->MODER = GPIOA->MODER | (1<<10);
	GPIOA->OTYPER = 0x0000;
	
	GPIOA->OSPEEDR = 0x00000000;
	
	while(1)
	{
		GPIOA->ODR = GPIOA->ODR | (1<<5);
		delay(500000);delay(500000);
		GPIOA->ODR = GPIOA->ODR & (~(1<<5));
		delay(500000);delay(500000);
	}
}