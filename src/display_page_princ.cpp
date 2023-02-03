/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#include <Arduino.h>
#include <Nextion.h>
#include <SPI.h>

#include "display.h"


void display_page_princ_show();


extern NexPage page_princ;
extern NexPicture p_led_bat_p;
extern NexPicture p_led_l30_p;
extern NexPicture p_led_l15_p;
extern NexHotspot m_bat_p;
extern NexHotspot m_l30_p;
extern NexHotspot m_l15_p;
extern NexVariable va_engine;

extern bool out_bat;
extern bool out_l15;
extern bool out_l30;




void display_page_princ_show(){
    page_princ.show();
    
    
   
}
