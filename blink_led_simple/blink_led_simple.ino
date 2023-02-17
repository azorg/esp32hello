/*
 * Безобразно простой "Blink LED" для ESP32 DOIT DEVKIT v1
 */

#define LED LED_BUILTIN // голубой светодиод на плате подключен к GPIO2 и GND
                        // красный светодиод горит при включении питания

#define BAUDRATE 115200 // скорость UART бит/с

void setup() {
  // put your setup code here, to run once:

  // set pin mode to output
  pinMode(LED, OUTPUT);

  // print "Hello ESP32" to UART
  Serial.begin(BAUDRATE);
  Serial.println("\nHello ESP32!\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(200);

  digitalWrite(LED, LOW);
  delay(800);
}
