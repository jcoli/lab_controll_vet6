/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#ifndef __IO_DEFINES_H__
#define __IO_DEFINES_H__

#define SPIWIFI       SPI  // The SPI port
// #define MOSI          PA7
// #define MISO          PA6
// #define SCK           PA5
#define SPIWIFI_SS    PA4   // Chip select pin
#define ESP32_RESETN  PA2   // Reset pin
#define SPIWIFI_ACK   PA3   // a.k.a BUSY or READY pin
#define ESP32_GPIO0   -1



#endif