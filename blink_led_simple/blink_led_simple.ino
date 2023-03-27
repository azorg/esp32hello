/*
 * Безобразно простой "Blink LED" для ESP32 DOIT DEVKIT v1
 */

#define LED LED_BUILTIN  // голубой светодиод на плате подключен к GPIO2 и GND \
                         // красный светодиод горит при включении питания

#define BAUDRATE 115200  // скорость UART бит/с

void setup() {
  // set pin mode to output
  pinMode(LED, OUTPUT);

  // print "Hello ESP32" to UART
  Serial.begin(BAUDRATE);
  Serial.println("\nHello ESP32!\n");
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(200);

  digitalWrite(LED, LOW);
  delay(800);
}
