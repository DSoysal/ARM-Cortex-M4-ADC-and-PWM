#include <TM4C123GH6PM.h>
#include "initialize.h"
#include "delay.h"

int main(){
	pwm_init();
	gpioPF2_init(); //output
	gpioPB4_init(); //input
	adc_init();

	int duty_cycle = 0;
	
  while(1)
  {
		  ADC0->PSSI |= (1<<3); // start sampling
		  while((ADC0->RIS & 8) == 0)  // wait until sampling is complete
      duty_cycle = (ADC0->SSFIFO3 - 96) * 4;
			
			ADC0->ISC |= (1<<3); // clear conversion flag 
      if (duty_cycle >= 16000) {duty_cycle = 0;}
      PWM1->_3_CMPA = 16000 - duty_cycle;
      delay_100ms();
  }		
}