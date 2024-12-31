#include <TM4C123GH6PM.h>

void gpioPF2_init(void);
void pwm_init(void);
void gpioPB4_init(void);
void timer0_init(void);
void adc_init(void);

void gpioPF2_init(void){
SYSCTL->RCGCGPIO |= 0x20;   
__ASM("NOP");
__ASM("NOP");
__ASM("NOP");
	
GPIOF->AFSEL |= (1<<2);     
GPIOF->PCTL &= ~0x00000F00; 
GPIOF->PCTL |= 0x00000500; 
GPIOF->DEN |= (1<<2);      
}
void pwm_init(void){
SYSCTL->RCGCPWM |= 2;     
__ASM("NOP");
__ASM("NOP");
__ASM("NOP"); 
__ASM("NOP");
__ASM("NOP"); 	
__ASM("NOP");
	
	
PWM1->_3_CTL &= ~(1<<0);   
PWM1->_3_CTL |= (1<<1);   // count UP
PWM1->_3_GENA = 0x0000008C; 
PWM1->_3_LOAD = 16000;   
PWM1->_3_CMPA = 8000-1;  
PWM1->_3_CTL = 1;       
PWM1->ENABLE = 0x40;      
}

void gpioPB4_init(void){
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

	








    