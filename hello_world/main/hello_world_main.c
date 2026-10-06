#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUTTON_PIN GPIO_NUM_0
#define LED_PIN GPIO_NUM_2

void app_main(void)
{
    // Configure button as input
    gpio_reset_pin(BUTTON_PIN);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUTTON_PIN, GPIO_PULLUP_ONLY);

    // Configure LED as output
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1)
    {
        int value = gpio_get_level(BUTTON_PIN);

        if (value == 0)
        {
            gpio_set_level(LED_PIN, 1);
        }
        else
        {
            gpio_set_level(LED_PIN, 0);
        }

        printf("The result is = %d\n", value);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}