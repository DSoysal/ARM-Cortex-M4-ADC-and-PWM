#include <TM4C123GH6PM.h>
#include <stdio.h>
#include "initialize.h"
#include "write.h"
#include "delay.h"

int main() {
  float adc_value; 
	char output[100];
	
	// initialize PB4 as parallel I/O and ADC0 with ss3
	gpio_init(); 
	adc_init();
	UART0_init();
  	
	  
	while(1){
		ADC0->PSSI |= (1<<3); // start sampling
		while((ADC0->RIS & 8) == 0)  // wait until sampling is complete
		adc_value = ((float)ADC0->SSFIFO3 * 3.3) / 4095.0 - 1.65; // Scale ADC value to voltage

		ADC0->ISC |= (1<<3); // clear conversion flag 	
	
		sprintf(output,"voltage value = %.3f V\r\n", adc_value);
		printstring(output);
		delay_1s();			
	}
}
