/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "led_strip.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#define ONBOARD_LED 27

void setup(){
    gpio_reset_pin(ONBOARD_LED);
    gpio_set_direction(ONBOARD_LED, GPIO_MODE_OUTPUT);
}

void app_main() {
  //#ifdef CONFIG_BLINK_LED_RMT
  //static led_strip_t *LEDs;
  //LEDs = led_strip_init(CONFIG_BLINK_LED_RMT_CHANNEL, BLINK_GPIO, 1);
  setup();
  while (true)
  {
    gpio_set_level(ONBOARD_LED, 1);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    gpio_set_level(ONBOARD_LED, 0);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}
