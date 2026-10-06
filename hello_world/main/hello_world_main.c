#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define button GPIO_NUM_0
#define LED_button GPIO_NUM_2
void app_main(void){
gpio_reset_pin(button);
gpio_set_direction(button,GPIO_MODE_INPUT);
gpio_set_pull_mode(button,GPIO_PULLUP_ONLY);

//next pin
gpio_reset_pin(LED_button);
gpio_set_direction(LED_button,GPIO_MODE_OUTPUT);
// next is define the variable 
int LED_state=0;
int LED_prev_state=1;
while (1){
int current_state=gpio_get_level(button);
if (LED_prev_state==1 && current_state==0 ) {
    LED_state=!LED_state;
    gpio_set_level(LED_button,LED_state);
}
LED_prev_state=current_state;
vTaskDelay(pdMS_TO_TICKS(50));

 }

}