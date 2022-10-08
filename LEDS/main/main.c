/*#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <inttypes.h>
#include "led_strip.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"*/
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

//#define ONBOARD_LED 27
const int LEDs[] = {25,26,14};

void setup(){
    //int LEDs = [25,26,27];
    //ESP_LOGI("example","test");
    //ESP_LOGI(sizeof(LEDs));
    //for (int i = 0; i < sizeof(LEDs); i++)
    //{
     // gpio_reset_pin(LEDs[i]);
      //gpio_set_direction(LEDs[i], GPIO_MODE_OUTPUT);
      //if (i == sizeof(LEDs))
      //  break;
    //}
    gpio_reset_pin(LEDs[0]);
    gpio_set_direction(LEDs[0], GPIO_MODE_OUTPUT);
    gpio_reset_pin(LEDs[1]);
    gpio_set_direction(LEDs[1], GPIO_MODE_OUTPUT);
    gpio_reset_pin(LEDs[2]);
    gpio_set_direction(LEDs[2], GPIO_MODE_OUTPUT);
}

void app_main() {
  //#ifdef CONFIG_BLINK_LED_RMT
  //static led_strip_t *LEDs;
  //LEDs = led_strip_init(CONFIG_BLINK_LED_RMT_CHANNEL, BLINK_GPIO, 1);
  setup();
  int x = 0;
  //string num = x;
  //int y = sizeof(LEDs);
  //printf("%c", y);
  //for (int x = 0; x < sizeof(LEDs); x++)
  while (true)
  {
    //string num = x;
    //ESP_LOGI("example",num);
    //if (x != sizeof(LEDs) && x < sizeof(LEDs))
    //{
      gpio_set_level(LEDs[x], 1);
      vTaskDelay(100 / portTICK_PERIOD_MS);
      gpio_set_level(LEDs[x], 0);
      vTaskDelay(100 / portTICK_PERIOD_MS);
    //}
    //else if (x == sizeof(LEDs))
     // x = 0;
    //else
     // continue;
    x++;
    //if (x == (sizeof(LEDs)-1))
    if (x == 3)
    {
      ESP_LOGI("Cycle","Completed");
      x = 0;
    }
    else
      continue;
  }
}
