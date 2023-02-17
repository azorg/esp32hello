/*
 * Безобрасно простой "Blink LED" для ESP32 DOIT DEVKIT v1
 */

#define LED 2 // голубой светодиод на плате подключен к GPIO2 и GND
// красный светодиод горит при включении питания

void setup() {
  // put your setup code here, to run once:

  // set pin mode to output
  pinMode(LED, OUTPUT);

  // print "Hello ESP32" to UART
  Serial.begin(115200);
  Serial.print("\nHello ESP32!\n\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(200);

  digitalWrite(LED, LOW);
  delay(800);
}
