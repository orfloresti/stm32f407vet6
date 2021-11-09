//Where is the led connected?
//Port:  A
//Pin:   5

// Data sheet memory map
#define PERIPH_BASE				(0x40000000UL)

// Block diagram to understand the internal connection
// Data sheet memory map to get the symbolic to the AHB1
#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE	        (PERIPH_BASE + AHB1PERIPH_OFFSET)

// Set the initial value depending of the port
#define GPIOA_OFFSET			(0x0000UL)
#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define GPIOC_OFFSET			(0x0800UL)
#define GPIOC_BASE				(AHB1PERIPH_BASE + GPIOC_OFFSET)

// Set the offset for the use of RCC
#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

// Reference manual RCC_AHB1ENR RCC AHB1 peripheral clock enable register
#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R            (*(volatile unsigned int *)(RCC_BASE +  AHB1EN_R_OFFSET))

// Reference manual GPIOx_MODER
#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define GPIOC_MODE_R			(*(volatile unsigned int *)(GPIOC_BASE + MODE_R_OFFSET))


// Reference manual GPIO port output data register (GPIOx_ODR)
#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE +  OD_R_OFFSET))

#define GPIOC_OD_R				(*(volatile unsigned int *)(GPIOC_BASE +  OD_R_OFFSET))

// Reference manual RCC_AHB1ENR
#define  GPIOAEN				(1U<<0) //   0b 0000 0000 0000 0000 0000 0000 0000 0001
#define  GPIOCEN				(1U<<2) //   0b 0000 0000 0000 0000 0000 0000 0000 0001

// GPIOx_ODR
#define PINA5					(1U<<5)
#define PA5					 	PINA5

#define PINC13					(1U<<13)
#define LED_PIN					PINC13

/*
 * (1U<<10)  // Set bit 10 to 1
 *  &=~(1U<<11) //  Set bit 11 to 0*/

int main(void)
{
	/*1. Enable clock access to GPIOA*/
	// RCC_AHB1EN_R  |=  GPIOAEN;
	RCC_AHB1EN_R  |=  GPIOCEN;

	/*2.Set PA5 as output pin*/
	// GPIOA_MODE_R  |= (1U<<10);  // Set bit 10 to 1
	// GPIOA_MODE_R  &=~(1U<<11); //  Set bit 11 to 0

	GPIOC_MODE_R |= (1U<<26);
	GPIOA_MODE_R  &=~(1U<<27);

	while(1)
	{
		/*3.Set PA5 high*/
		//GPIOA_OD_R |= LED_PIN;

		/*4:Experiment 2 : toggle PA5*/
		// GPIOA_OD_R ^= PA5;
		GPIOC_OD_R ^= LED_PIN;

		for(int i=0;i<100000;i++){}

	}
}




