#include <Arduino.h>
#include "Config.h"
#include "I2c.h"
#include "I2S.h"
#include "LittleFSM.h"
#include "OLED.h"
#include "IMU.h"
#include "MEDIA.h"
#include "ImageRender.h"
#include "WiFiM.h"
#include "WebM.h"

void bootAnim();
void updateIMU();

void setup() {
  Serial.begin(1120000);
  delay(100);
  I2c::init();
  LittleFSM::init();
  I2S::init();
  MediaManager::init();
  if (WiFiM::init()) {
    WebM::init();
    WiFiM::getIP().toString();
  }
  bootAnim();
}

void loop() {
  WebM::handle();
  updateIMU();
}

void updateIMU() {
  uint32_t now = millis();
  if (IMU::getGyroX) {
    IMU::update();
  }
}