#include "inc/tm4c123gh6pm.h"

#define TRUE 1

void main(int argc, char *argv[])
{
  SYSCTL_RCGCGPIO_R = 0x21U;
  GPIO_PORTF_DIR_R = 0x0EU;
  GPIO_PORTA_DIR_R = 0x1CU;
  GPIO_PORTF_DEN_R  = 0x0EU;
  GPIO_PORTA_DEN_R  = 0x1CU;
  unsigned int signal_counter = 0;
  unsigned int led_color = 0x00U;

  while(TRUE)
  {
    if(led_color <= 0x00U)
    {
        led_color = 0x0EU;
    }

    GPIO_PORTF_DATA_R = led_color;

    int counter = 0;
    while (counter < 1000000){
      ++counter;
    }

    if (signal_counter < 5)
    {
        GPIO_PORTA_DATA_R = 0x04U; //green on
    }

    else if (signal_counter == 8)
    {
        GPIO_PORTA_DATA_R = 0x08U; //yellow on
    }
    else if (signal_counter == 10)
    {
        GPIO_PORTA_DATA_R = 0x10U; //red on
    }
    else if(signal_counter == 15)
    {
        signal_counter = 0;
    }
    signal_counter++;
    led_color--;
  }
}
