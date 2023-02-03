/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#ifndef __DEFINES_H__
#define __DEFINES_H__

/* defines */
#define V03_MAX 3.6
#define V05_MAX 5.5
#define V12_MAX 14.5
#define V24_MAX 28.0

static const char version[] = "0.0a";
static const char develop[] =  "jcoli-Tecnocoli";
static const char email_develop[] = "jcoli@tecnocoli.com.br";
static const char processor[] = "STM32F407VET6";

#define TIMER_INTERVAL_0_1S           100L
#define TIMER_INTERVAL_0_3S           300L
#define TIMER_INTERVAL_1S             1000L
#define TIMER_INTERVAL_1_5S           1500L
#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     0 
#define TIMER_INTERVAL_MS         100
#define HW_TIMER_INTERVAL_MS      50

#define TIMER_SLEEP 1000000
#define TIMER_ANALOG 5000
#define TIMER_MQTT 80
#define TIMER_SEND_MQTT 5000


#define BROKER_ADDR  IPAddress(192,168,61,85)
#define BROKER_USERNAME     "mqtt_user" // replace with your credentials
#define BROKER_PASSWORD     "shady55"
#define DEVICE_NAME "Lab_Control_5"

#define LOCAL_IP IPAddress(192,168,61,40)
#define LOCAL_SSID "IOT-2"
#define LOCAL_PASS "shady6565"


#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFD20      /* 255, 165,   0 */
#define GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define PINK        0xF81F

#endif