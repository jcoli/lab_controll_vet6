/**
Version: 0a
Tecnocoli - 12/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Lab Controll
**/

#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include "defines.h"
#include "io_defines.h"

void printMacAddress(byte mac[]);
void printCurrentNet();
void printWifiData();
void printEncryptionType(int thisType);
void listNetworks();
void wifi_nina_beging();
void checkStatus_wifi();

char ssid[] = LOCAL_SSID;        // your network SSID (name)
char pass[] = LOCAL_PASS;    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;
String s_status = "WL_NO_MODULE";

String status_char[11] =  {"IDLE_STATUS", "NO_SSID_AVAIL", "SCAN_COMPLETED", "CONNECTED", 
    "CONNECT_FAILED", "CONNECTION_LOST", "DISCONNECTED", "AP_LISTENING", "AP_CONNECTED", "AP_FAILED", "NO_MODULE"};

byte mac[6];
byte new_mac[] = {0x00, 0x10, 0xFA, 0x6E, 0x38, 0x4A};
extern bool wifi_connected;
uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66};

void wifi_nina_begin(){
  Serial.println("WiFiNINA firmware check.");
  Serial.println();
  Serial.println(ssid);
  Serial.println(pass);
    // Set up the pins!
  WiFi.setPins(SPIWIFI_SS, SPIWIFI_ACK, ESP32_RESETN, ESP32_GPIO0, &SPIWIFI);
  WiFi.config(LOCAL_IP);
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }
 
  // Print firmware version on the module
  String fv = WiFi.firmwareVersion();
  String latestFv;
  Serial.print("Firmware version installed: ");
  Serial.println(fv);
 
  latestFv = WIFI_FIRMWARE_LATEST_VERSION;

  // Print required firmware version
  Serial.print("Latest firmware version available : ");
  Serial.println(latestFv);
 
  // Check if the latest version is installed
  Serial.println();
  if (fv >= latestFv) {
    Serial.println("Check result: PASSED");
  } else {
    Serial.println("Check result: NOT PASSED");
    Serial.println(" - The firmware version on the module do not match the");
    Serial.println("   version required by the library, you may experience");
    Serial.println("   issues or failures.");
  }
    WiFi.macAddress(mac);
    Serial.print("MAC: ");
    printMacAddress(mac);
    int tent = 0;
    while ((status != WL_CONNECTED) && (tent<30)) {
        status = WiFi.begin(ssid, pass);
        // status = WiFi.begin(ssid);
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        Serial.println(status);
        tent++;
        if (status != WL_CONNECTED){
          delay(4000);
        }
    }
    if (status == WL_CONNECTED){
        Serial.println("You're connected to the network");
        wifi_connected = true;
    }
    delay(2000);
   
    printCurrentNet();
    printWifiData();
}


void checkStatus_wifi(){
  status = WiFi.status();
  if (status != WL_CONNECTED){
     int tent = 0;
      while ((status != WL_CONNECTED) && (tent<30)) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        Serial.println(status);
        // Connect to WPA/WPA2 network:
        status = WiFi.begin(ssid, pass);
        tent++;
        // wait 10 seconds for connection:
        delay(2000);
    }
  }
  if (status == WL_CONNECTED){
    wifi_connected = true;
  }else{
    wifi_connected = false;
  }
}

void printCurrentNet() {
  
  Serial.print("SSID: ");
  Serial.print(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("  IP Address: ");
  Serial.print(ip);
  Serial.print("  Status: ");
  if (status > 9 ) status = 11;
  Serial.print(status_char[status]);
  byte bssid[6];
  WiFi.BSSID(bssid);
  long rssi = WiFi.RSSI();
  Serial.print("  signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println();
}


void listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");

  int numSsid = WiFi.scanNetworks();
  Serial.println("** Scan Networks **");
  if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }
 
  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);
 
  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
  }
}
 
void printEncryptionType(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
    case ENC_TYPE_UNKNOWN:
    default:
      Serial.println("Unknown");
      break;
  }
}

void printWifiData() {
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printMacAddress(mac);
}



void printMacAddress(byte mac[]) {
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0) {
      Serial.print(":");
    }
  }
  Serial.println();
}


/*
GPIO05	          CS	              PA4
GPIO18	          SCK	              PA5
GPIO23	          MISO	            PA6
GPIO14	          MOSI	            PA7
GPIO33	          BUSY/READY (IRQ)	PA3
EN (reset on LOW)	RST/EN	          PA2
GND	              GND	              GND
VIN	3.3v
*/