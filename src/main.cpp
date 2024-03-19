#include <Arduino.h>
#include <lvgl.h>
#include <ATD3.5-S3.h>
#include "gui/ui.h"

#define LED_Y_PIN (5)

void setup() {
  Serial.begin(115200);
  
  // Setup peripherals
  Display.begin(0); // rotation number 0
  Touch.begin();
  Sound.begin();
  // Card.begin(); // uncomment if you want to Read/Write/Play/Load file in MicroSD Card
  pinMode(LED_Y_PIN, OUTPUT);
  digitalWrite(LED_Y_PIN, HIGH); // off LED Y
  
  // Map peripheral to LVGL
  Display.useLVGL(); // Map display to LVGL
  Touch.useLVGL(); // Map touch screen to LVGL
  Sound.useLVGL(); // Map speaker to LVGL
  // Card.useLVGL(); // Map MicroSD Card to LVGL File System

  Display.enableAutoSleep(120); // Auto off display if not touch in 2 min
  
  // Add load your UI function
  ui_init();

  // Add event handle
  lv_obj_add_event_cb(ui_led_switch, [](lv_event_t * e) { // Add click LED switch event handle
    lv_obj_t * target = lv_event_get_target(e);
    if (lv_obj_has_state(target, LV_STATE_CHECKED)) { // if switch on
      digitalWrite(LED_Y_PIN, LOW); // ON LED Y
    } else {
      digitalWrite(LED_Y_PIN, HIGH); // OFF LED Y
    }
  }, LV_EVENT_CLICKED, NULL);
}

void loop() {
  Display.loop(); // Keep GUI work
}
