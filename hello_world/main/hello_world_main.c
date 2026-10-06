#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define button GPIO_NUM_0
#define LED_button GPIO_NUM_2
void app_main(void) {
gpio_reset_pin(button);
gpio_set_direction(button,GPIO_MODE_INPUT);
gpio_set_pull_mode(button,GPIO_PULLUP_ONLY);
int prev_state=1;
while (1){
    int current_state=gpio_get_level(button);
    if (current_state !=prev_state ){
    printf("the button changed from %d to %d\n",prev_state, current_state);
}
prev_state=current_state;
vTaskDelay(pdMS_TO_TICKS(10));
}
}