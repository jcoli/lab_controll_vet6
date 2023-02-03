/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#include <Arduino.h>
#include <Nextion.h>
#include <SPI.h>

#include "display_page_princ.h"
#include "defines.h"

void display_update();
void display_begin();
void display_init();
void display_listen();

extern bool wifi_connected;
extern bool mqtt_connected;



NexHotspot m_bat_p = NexHotspot(0, 8, "m_bat");
NexHotspot m_l30_p = NexHotspot(0, 9, "m_l30");
NexHotspot m_l15_p = NexHotspot(0, 10, "m_l15");

NexPicture p_led_bat_p = NexPicture(0,14, "p_led_bat");
NexPicture p_led_l30_p = NexPicture(0,15, "p_led_l30");
NexPicture p_led_l15_p = NexPicture(0,16, "p_led_l15");

NexVariable va_engine = NexVariable(0, 3, "va_engine");
NexVariable page_cur = NexVariable(0, 13, "va_cur");

NexPage page_princ = NexPage(0, 0, "page_princ");
NexPage page_splash = NexPage(1, 0, "page_splash");
NexPage page_digital = NexPage(2, 0, "page_digital");
NexPage page_analog = NexPage(3, 0, "page_analog");
NexPage page_graphic = NexPage(4, 0, "page_graphic");
NexPage page_odb2 = NexPage(5, 0, "page_odb2");
NexPage page_info = NexPage(6, 0, "page_info");



NexTouch *nex_listen_list[] = {
    &m_bat_p,
    &m_l30_p,
    &m_l15_p,
    NULL};

void display_begin(){
    nexInit();
    page_splash.show();
    delay(5000);
    display_page_princ_show();
    p_led_bat_p.setPic(38);
     p_led_l30_p.setPic(52);
    Serial3.write("play 0,4,0");  //SLEEPING
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
    delay(200); 
    
    
    // Serial.println("display");
    
}

void display_update(){
    if (wifi_connected){
        p_led_bat_p.setPic(114);
    }else{
        p_led_bat_p.setPic(38);
    }  
    // Serial.println("display update");  
    if (mqtt_connected){
        p_led_l30_p.setPic(51);
    }else{
        p_led_l30_p.setPic(52);
    }
    
}

void display_init(){


}  

void display_listen(){
    nexLoop(nex_listen_list);
}  



