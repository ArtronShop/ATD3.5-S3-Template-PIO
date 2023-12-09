#include <Arduino.h>
#include <ATD3.5-S3.h>

void setup() {
  Serial.begin(115200);
  Display.begin();
}

void loop() {
  // Check base color correct
  Display.fillScreen(0xF800); // Red
  delay(500);
  Display.fillScreen(0x07E0); // Green
  delay(500);
  Display.fillScreen(0x001F); // Blue
  delay(500);
  Display.fillScreen(0x0000); // Blank
  delay(500);
  Display.fillScreen(0xFFFF); // White
  delay(500);

  // Test fill screen
  for (int i=0;i<20;i++) {
    uint16_t color = random(0x0000, 0xFFFF);
    Display.fillScreen(color);
  }
  
  // Test draw circle
  Display.fillScreen(0x0000);
  for (int i=0;i<20;i++) {
    int size = random(10, 50);
    int x = random(size, 480 - size);
    int y = random(size, 320 - size);
    uint16_t color = random(0x0000, 0xFFFF);
    Display.fillCircle(x, y, size, color);
  }

  // Test draw rect
  Display.fillScreen(0x0000);
  for (int i=0;i<20;i++) {
    int x1 = random(0, 480);
    int y1 = random(0, 320);
    int x2 = random(x1, 480 - x1);
    int y2 = random(y1, 320 - y1);
    uint16_t color = random(0x0000, 0xFFFF);
    Display.fillRect(x1, y1, x2, y2, color);
  }
  
  // Test draw triangle
  Display.fillScreen(0x0000);
  for (int i=0;i<20;i++) {
    int w = random(10, 50);
    int h = random(10, 50);
    int xc = random(0, 480 - w);
    int yc = random(0, 320 - h);
    int angle = random(0, 359);
    uint16_t color = random(0x0000, 0xFFFF);
    Display.drawTriangle(xc, yc, w, h, angle, color);
  }
}
