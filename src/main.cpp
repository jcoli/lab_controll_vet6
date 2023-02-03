/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#include <Arduino.h>

#include <Nextion.h>
#include <SPI.h>

#include "defines.h"
#include "io_defines.h"
#include "wifi_nina.h"
#include "display.h"
#include "mqtt_controll.h"

// HardwareSerial Serial2(PA3, PA2);
HardwareSerial Serial3(PB11, PB10);

bool wifi_connected = false;
bool mqtt_connected = false;

int year = 0;
int month = 0;
int day = 0;
int hour = 0;
int minute = 0;
int second = 0;

unsigned long loopDelay = millis();
unsigned long loopDelay_readValue = millis();
unsigned long loopDelay_cycle = millis();
unsigned long loopDelay_toSleep = millis();
unsigned long loopDelay_toScreen = millis();
unsigned long loopDelay_wave = millis();

unsigned long loopDelay_analog = millis();
unsigned long loopDelay_input = millis();
unsigned long loopDelay_mqtt = millis();
unsigned long lastAvailabilityToggleAt = millis();

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Init......");
  display_begin();
  delay(500);
  wifi_nina_begin();
  delay(500);
  Serial.println("wifi");
  mqtt_begin();
  delay(500);
  checkStatus_wifi();
  checkStatus_mqtt();
  display_update();
}

void loop() {
  display_listen();
  
  if (millis() - loopDelay_mqtt > TIMER_MQTT){
    loopDelay_mqtt = millis();
    mqtt_loop();
    //io_input_controll();    
  } 
  if (millis() - loopDelay > 20000){
    loopDelay = millis();
    Serial.println("Loop");
    checkStatus_wifi();
    printCurrentNet();
    checkStatus_mqtt();
    display_update();

  }    
  
}