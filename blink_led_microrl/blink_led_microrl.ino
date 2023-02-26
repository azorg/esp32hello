/*
 * Еще один "Blink LED" для Arduino с использованием ABlink, ATicker, MicroRL
 */

//-----------------------------------------------------------------------------
#include "config.h"
#include "global.h"
#include "cli.h"
//-----------------------------------------------------------------------------
// функция вызываемая тикером
void ticker_callback() {

  // моргать светодиодом дважды каждые 10 секунд
  if ((Ticks % (10 * TICKER_HZ)) == 0) Led.blink(2);

  Ticks++;
}
//-----------------------------------------------------------------------------
void setup() {
  // setup UART
  Serial.begin(BAUDRATE);

  // init CLI (MicroRL)
  cli_init();
  Serial.flush();

  // setup blink LED
  Led.begin(LED, LED_INVERT, LED_BLINK_ON, LED_BLINK_OFF);

  // setup ticker
  Ticker.begin(ticker_callback, TICKER_MS, true, millis());
}
//-----------------------------------------------------------------------------
void loop() {
  unsigned long t = millis();
  Led.yield(t);
  Ticker.yield(t);
  cli_loop();
}
//-----------------------------------------------------------------------------
/*** end of "blink_led_microrl.ino" file ***/

