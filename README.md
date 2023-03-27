Первый проект "Hello world" (sketch) для ESP32 в Arduino IDE
============================================================

# Ссылки на документацию

 * https://docs.espressif.com/projects/arduino-esp32/en/latest/

 * Кое-что полезное лежит в папке `doc`

# Скетчи (в порядке создания и повышения "сложности"):

 1. `blink_led_simple` - моргание светодиодом с задержками (плохая практика, простой пример)

 2. `blink_led_timer` - моргание светодиодом с использованием прерываний от таймера

 3. `blink_led_class` - моргание светодиодом с использованием C++ модуля ALed.cpp/ALed.h
 
 4. `blink_led_arduino` - моргание светодиодом с использованием классов (ABlink, ATicker)

 5. `blink_led_microrl` - моргание светодиодом и CLI интерфейс на основе MicroRL
 
 6. `blink_led_usbcdc` - моргание светодиодом c выводом сообщений на USB-CDC (Lolin S2mini)

# Полезные команды:

 * `esptool.py -p /dev/ttyUSB0 chip_id` - узнать версию чипа ESP32

# Порядок установки Arduino IDE + ESP32 под Linux
см. файл INSTALL.md

