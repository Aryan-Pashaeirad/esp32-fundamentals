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
// next pin(output)
gpio_reset_pin(LED_button);
gpio_set_direction(LED_button,GPIO_MODE_OUTPUT);
int stable_state=1;
int LED_state=0;
gpio_set_level(LED_button,LED_state);
while (1){
int raw_state=gpio_get_level(button);
if (raw_state!=stable_state){
    vTaskDelay(pdMS_TO_TICKS(10));
    int confirm_state=gpio_get_level(button);
    if (confirm_state==raw_state){
        stable_state=confirm_state;
    // only react to the real valid press
    if (stable_state==0){
        LED_state=!LED_state;
        gpio_set_level(LED_button,LED_state);
        printf("the valid press=%d\n",LED_state);
     }

   }
}
vTaskDelay(pdMS_TO_TICKS(10));
}

}