/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#ifndef __WIFI_NINA_H__
#define __WIFI_NINA_H__

void printMacAddress(byte mac[]);
void printCurrentNet();
void printWifiData();
void printEncryptionType(int thisType);
void listNetworks();
void wifi_nina_begin();
void checkStatus_wifi();



#endif