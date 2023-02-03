/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#include <Arduino.h>
#include <ArduinoHA.h> //MQTT
#include <WiFi.h>

#include "defines.h"
#include "io_defines.h"
#include "wifi_nina.h"
#include "display.h"

void mqtt_begin();
void mqtt_loop();
void onMqttConnected();
void mqtt_update();
void onMqttMessage(const char* topic, const uint8_t* payload, uint16_t length); 
void on_switch_1(bool state, HASwitch* sender);
void checkStatus_mqtt();


WiFiClient wifiClient;

extern bool wifi_connected;
extern bool mqtt_connected;
extern int year;
extern int month;
extern int day;
extern int hour;
extern int minute;
extern int second;

HADevice device;
HAMqtt mqtt(wifiClient, device, 20);
HASwitch switch_1("switch_lab_1");

byte unique[6];

void mqtt_begin(){
    Serial.println("mqtt");
    // device.enableSharedAvailability();
    device.enableLastWill();
    // mqtt.onMessage(callback_mqtt);
    Serial.println("mqtt1z");

    unique[0] = 77;
    unique[1] = 07;
    unique[2] = 68;
    unique[3] = 35;
    unique[4] = 72;
    unique[5] = 49;

    Serial.println("mqtt1");
  
    // WiFi.macAddress(mac);
    
    device.setUniqueId(unique, 6);
    device.setName(DEVICE_NAME);
    device.setSoftwareVersion("0.1.a");
    device.setManufacturer("Tecnocoli");
    device.setModel("0A");

    mqtt.onMessage(onMqttMessage);
    mqtt.onConnected(onMqttConnected);

    switch_1.setName("Switch Lab 1");
    switch_1.onCommand(on_switch_1);
    switch_1.setIcon("mdi:tumble-dryer"); 
    switch_1.setState(false);  

    

    Serial.println("mqtt2");
    if (wifi_connected){
        int status=mqtt.begin(BROKER_ADDR, BROKER_USERNAME, BROKER_PASSWORD);
        
        Serial.print("Broker: ");
        Serial.println(status);
        
    } 
    
    if (mqtt.isConnected()){
      Serial.println("mqtt 3");
    }else{
      Serial.println("mqtt 3a");
    }
    
    delay(1000);
}

void checkStatus_mqtt(){
    if (mqtt.isConnected()){
      mqtt_connected = true;
    }else{
      mqtt_connected = false;
    }
}


void mqtt_loop(){
    mqtt.loop();
    mqtt_connected = mqtt.isConnected();
}

void on_switch_1(bool state, HASwitch* sender){
    Serial.println("Switch On");

}

void onMqttConnected() {
    Serial.println("Connected to the broker!");
    mqtt.subscribe("date_stamp");
    mqtt.subscribe("dryer_program_select_5");
    // You can subscribe to custom topic if you need
    // mqtt.subscribe("switch.liga");
}

void mqtt_update(){
    Serial.println("Mqtt Update");
}

void onMqttMessage(const char* topic, const uint8_t* payload, uint16_t length) {
    // This callback is called when message from MQTT broker is received.
    // Please note that you should always verify if the message's topic is the one you expect.
    // For example: if (memcmp(topic, "myCustomTopic") == 0) { ... }
    Serial.println("==========================");
    Serial.print("New message on topic: ");
    Serial.println(topic);
    Serial.print("Data: ");
    Serial.println((const char*)payload);
    Serial.println("==========================");

    // mqtt.publish("myPublishTopic", "hello");
}

