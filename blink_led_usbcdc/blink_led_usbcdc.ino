/*
 * Безобразно простой "Blink LED" для ESP32 Lolon S2 mini (+USBCDC)
 */
 
#define LED LED_BUILTIN // светодиод на плате подключен
#define BAUDRATE 115200 // скорость UART бит/с

#include "usbcdc.h"

int cnt = 0;

void setup() {
  // set pin mode to output
  pinMode(LED, OUTPUT);

  // setup UART
  HWSerial.begin(BAUDRATE);

  // setup USB-CDC
  usbcdc_begin();
  
  HWSerial.println("\r\nHello ESP32! (UART)\r\n");
  USBSerial.println("\r\nHello ESP32! (USB-CDC)\r\n");

  cnt = 0;
}

void loop() {
  //while (HWSerial.available()) {
  //  size_t l = HWSerial.available();
  //  uint8_t b[l];
  //  l = HWSerial.read(b, l);
  //  USBSerial.write(b, l);
  //}

  //HWSerial.printf("%i\r\n", cnt);
  //USBSerial.printf("%i\r\n", cnt);
  Serial.printf("%i\r\n", cnt);
  cnt++;

  digitalWrite(LED, HIGH);
  delay(200);

  digitalWrite(LED, LOW);
  delay(800);
}
