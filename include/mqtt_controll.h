/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/


#ifndef __MQTT_CONTROLL_H__
#define __MQTT_CONTROLL_H__

void mqtt_begin();
void mqtt_loop();
void onMqttConnected();
void mqtt_update();
void onMqttMessage(const char* topic, const uint8_t* payload, uint16_t length); 
void checkStatus_mqtt();



#endif