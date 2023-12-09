#include <Arduino.h>
#include <lvgl.h>
#include <ATD3.5-S3.h>
#include <lv_demos.h>

void setup() {
  Serial.begin(115200);

  Display.begin(3); // rotation number 3
  Touch.begin();

  Display.useLVGL();
  Touch.useLVGL();
  
  // lv_demo_music();
  lv_demo_widgets();
}

void loop() {
  Display.loop();
}
