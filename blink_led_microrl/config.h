/*
 * file: "config.h"
 */

#pragma once
#ifndef CONFIG_H
#define CONFIG_H
//-----------------------------------------------------------------------------
#define ABOUT_STRING "Arduino MicroRL test"
#define VERSION_SOFTWARE_STR "0.0.1" // software version
#define VERSION_HARDWARE_STR "1"     // hardware revision

#define BAUDRATE 115200 // скорость UART бит/с

#define LED LED_BUILTIN  // голубой светодиод на плате подключен к GPIO2 и GND
#define LED_INVERT false // признак инверсии сигнала управления светодиодом
#define LED_BLINK_ON  30 // время включения светодиода [мс]
#define LED_BLINK_OFF 70 // время выключения светодиода [мс]

#define TICKER_MS 10                 // период повторения тикера [мс]
#define TICKER_HZ (1000 / TICKER_MS) // частота тикера [Гц]

#define VERBOSE 0 // verbose level by default
//-----------------------------------------------------------------------------
#define CLI_HELP
#define PRINT_SERIAL
//#define DEBUG
//-----------------------------------------------------------------------------
#endif // CONFIG_H

/*** end of "config.h" file ***/

