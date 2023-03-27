/*
 * Простой "Blink LED" для ESP32 DOIT DEVKIT v1 с использованием таймера
 */

#define LED LED_BUILTIN // голубой светодиод на плате подключен к GPIO2 и GND
                        // красный светодиод горит при включении питания

#define BAUDRATE 115200 // скорость UART бит/с

#define SYSTEM_CLOCK_HZ 80000000 // тактовая частота (80 МГц)
#define TIMER_DEVIDER 80 // пределитель таймера
#define TIMER_FREQ_HZ 1000 // частота прерываний таймера [Гц]

#define LED_ON  100 // время включения светодиода в тиках таймера 
#define LED_OFF 900 // время выключения светодиода в тиках таймера 

// the hardware timer pointer
hw_timer_t * timer = (hw_timer_t *) NULL;

// we use it to ensure that the ISR and the loop
// do not try to access the interruptCounter variable
// at the same time
portMUX_TYPE timer_mux = portMUX_INITIALIZER_UNLOCKED;

volatile uint32_t timer_ticks = 0; // счетчик прерываний от таймера
volatile uint8_t timer_irq = 0; // флаг прерывания от таймера

// timer ISR (обработчик прерывания от таймера)
void IRAM_ATTR on_timer() {
  portENTER_CRITICAL_ISR(&timer_mux);
  timer_irq = 1;
  timer_ticks++;
  portEXIT_CRITICAL_ISR(&timer_mux);
}

uint8_t  led = LOW;   // состояние светодиода  
uint32_t led_cnt = 0; // счетчик в тиках таймера состояния светодиода

void setup() {
   // set LED pin mode to output
  pinMode(LED, OUTPUT);
  digitalWrite(LED, led = LOW);

  // setup timer #0
  timer = timerBegin(0, TIMER_DEVIDER, true);
  timerAttachInterrupt(timer, &on_timer, true);
  timerAlarmWrite(timer, SYSTEM_CLOCK_HZ / TIMER_DEVIDER / TIMER_FREQ_HZ, true);
  timerAlarmEnable(timer);

  // print "Hello ESP32" to UART
  Serial.begin(BAUDRATE);
  Serial.println("\r\nHello ESP32!");
  Serial.printf("Timer frequency = %i Hz\r\n", TIMER_FREQ_HZ);
  Serial.flush();
}

// функция вызываемая с частотой прерывания от таймера из контекста главного цикла
void timer_callback()
{
  if (led_cnt == 0)
  {
    if (led == LOW)
    {
      led = HIGH;
      led_cnt = LED_ON;
    }
    else // led == HIGH
    {
      led = LOW;
      led_cnt = LED_OFF;
    }
    digitalWrite(LED, led);
  }
  else
    led_cnt--;
}

// функция вызываемая из контектса главного цикла с периодом 1 сек
void on_second()
{
  Serial.printf("timer_ticks = %u\r\n", timer_ticks);
  Serial.flush();
}

void loop() {
  // имитировать обработчик от таймера
  uint32_t t0 = 0, t1;
  if (timer_irq) {
    timer_irq = 0;
    timer_callback();      
  }

  for (t1 = timer_ticks; t1 - t0 >= TIMER_FREQ_HZ; t0 += TIMER_FREQ_HZ) {
    on_second();
  }

  // TODO: тут хорошо бы перевести SoC в легкий сон до следующего прерывания таймера
}
