#include <TM4C123GH6PM.h>

void gpio_init(void);
void adc_init(void);

void gpio_init(void){
    SYSCTL->RCGCGPIO |= (1<<1);    
	  __ASM("NOP");
	  __ASM("NOP");
	  __ASM("NOP");
      
		GPIOB->AFSEL |= (1<<4); 
    GPIOB->DIR &= ~(1<<4);
    GPIOB->DEN &= ~(1<<4);
	  GPIOB->AMSEL |= (1<<4);	
}

void adc_init(void){
    SYSCTL->RCGCADC |= (1<<0);  
    __ASM("NOP");
	  __ASM("NOP");
	  __ASM("NOP");	
  	__ASM("NOP");
	  __ASM("NOP");
	  __ASM("NOP");
  
	
	  ADC0->ACTSS &= ~(1<<3);
	  ADC0->EMUX  &= ~0x0000F000;
	  ADC0->SSMUX3 = 0xA;
		ADC0->SSCTL3 |= (1<<2)|(1<<1); 
	  ADC0->PC &= ~0xF;
    ADC0->PC |= 0x01;	
	  ADC0->ACTSS |= (1<<3);	
}


	