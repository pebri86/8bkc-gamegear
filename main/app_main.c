#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "esp_partition.h"
#include "esp_log.h"

#include "8bkc-hal.h"
#include "appfs.h"

#include "smsplus-main.h"


uint16_t *oledBuf;
uint16_t *overlay;

void app_main()
{
	oledBuf=heap_caps_malloc(KC_SCREEN_W*KC_SCREEN_H*sizeof(uint16_t), MALLOC_CAP_DMA | MALLOC_CAP_8BIT);
	overlay=heap_caps_malloc(KC_SCREEN_W*KC_SCREEN_H*sizeof(uint16_t), MALLOC_CAP_DMA | MALLOC_CAP_8BIT);
	kchal_init();
//	nvs_flash_init();
	
	smsemuStart();
}


