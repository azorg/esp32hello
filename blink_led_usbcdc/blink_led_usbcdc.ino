/*
 * Безобразно простой "Blink LED" для ESP32 Lolon S2 mini (+USBCDC)
 */
 
#define LED LED_BUILTIN // светодиод на плате подключен
#define BAUDRATE 115200 // скорость UART бит/с

#if ARDUINO_USB_MODE
#warning This sketch should be used when USB is in OTG mode
// do nothing
void setup(){}
void loop(){}
#else
#include "USB.h"
#if ARDUINO_USB_CDC_ON_BOOT
#  define HWSerial Serial0
#  define USBSerial Serial
#else
#  define HWSerial Serial
USBCDC USBSerial;
#endif

static void usbEventCallback(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data){
  if(event_base == ARDUINO_USB_EVENTS){
    arduino_usb_event_data_t * data = (arduino_usb_event_data_t*)event_data;
    switch (event_id){
      case ARDUINO_USB_STARTED_EVENT:
        HWSerial.println("USB PLUGGED");
        break;
      case ARDUINO_USB_STOPPED_EVENT:
        HWSerial.println("USB UNPLUGGED");
        break;
      case ARDUINO_USB_SUSPEND_EVENT:
        HWSerial.printf("USB SUSPENDED: remote_wakeup_en: %u\n", data->suspend.remote_wakeup_en);
        break;
      case ARDUINO_USB_RESUME_EVENT:
        HWSerial.println("USB RESUMED");
        break;
      
      default:
        break;
    }
  } else if(event_base == ARDUINO_USB_CDC_EVENTS){
    arduino_usb_cdc_event_data_t * data = (arduino_usb_cdc_event_data_t*)event_data;
    switch (event_id){
      case ARDUINO_USB_CDC_CONNECTED_EVENT:
        HWSerial.println("CDC CONNECTED");
        break;
      case ARDUINO_USB_CDC_DISCONNECTED_EVENT:
        HWSerial.println("CDC DISCONNECTED");
        break;
      case ARDUINO_USB_CDC_LINE_STATE_EVENT:
        HWSerial.printf("CDC LINE STATE: dtr: %u, rts: %u\n", data->line_state.dtr, data->line_state.rts);
        break;
      case ARDUINO_USB_CDC_LINE_CODING_EVENT:
        HWSerial.printf("CDC LINE CODING: bit_rate: %u, data_bits: %u, stop_bits: %u, parity: %u\n", data->line_coding.bit_rate, data->line_coding.data_bits, data->line_coding.stop_bits, data->line_coding.parity);
        break;
      case ARDUINO_USB_CDC_RX_EVENT:
        HWSerial.printf("CDC RX [%u]:", data->rx.len);
        {
            uint8_t buf[data->rx.len];
            size_t len = USBSerial.read(buf, data->rx.len);
            HWSerial.write(buf, len);
        }
        HWSerial.println();
        break;
       case ARDUINO_USB_CDC_RX_OVERFLOW_EVENT:
        HWSerial.printf("CDC RX Overflow of %d bytes", data->rx_overflow.dropped_bytes);
        break;
     
      default:
        break;
    }
  }
}

int cnt = 0;

void setup() {
  // set pin mode to output
  pinMode(LED, OUTPUT);

  HWSerial.begin(BAUDRATE);
  HWSerial.setDebugOutput(true);
  
  USB.onEvent(usbEventCallback);
  USBSerial.onEvent(usbEventCallback);
  
  USBSerial.begin();
  USB.begin();

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

  HWSerial.printf("%i\r\n", cnt);
  USBSerial.printf("%i\r\n", cnt);
  cnt++;

  digitalWrite(LED, HIGH);
  delay(200);

  digitalWrite(LED, LOW);
  delay(800);
}

#endif // !ARDUINO_USB_MODE
