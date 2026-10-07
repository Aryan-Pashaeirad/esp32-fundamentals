#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define button GPIO_NUM_0
#define LED1 GPIO_NUM_2
#define LED2 GPIO_NUM_4
void app_main(void){
gpio_reset_pin(button);
gpio_set_direction(button,GPIO_MODE_INPUT);
gpio_set_pull_mode(button,GPIO_PULLUP_ONLY);
// LED1 configuration
gpio_reset_pin(LED1);
gpio_set_direction(LED1,GPIO_MODE_OUTPUT);
//LED2
gpio_reset_pin(LED2);
gpio_set_direction(LED2,GPIO_MODE_OUTPUT);
int state_led=1;
int step=0;

while (1){
int current_state=gpio_get_level(button);
if (current_state!=state_led){
    vTaskDelay(pdMS_TO_TICKS(10));
    int confirm_state=gpio_get_level(button);
    if (confirm_state==current_state){
        state_led=confirm_state;
      // valid press
    if (state_led==0){
        step=step+1;
        if (step>2){
            step=0;}
            printf("the currnt state=%d\n",step);
        
    }
    }
}

if (step==0){
    gpio_set_level(LED1,0);
    gpio_set_level(LED2,0);
}
else if (step==1){
    gpio_set_level(LED1,1);
    gpio_set_level(LED2,0);

}
else if (step==2) {
    gpio_set_level(LED1,0);
    gpio_set_level(LED2,1);

}
vTaskDelay(pdMS_TO_TICKS(10));
}
}