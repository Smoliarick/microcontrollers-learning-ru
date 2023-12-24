// даём имя для пина №9 и №11 со светодиодами
// (англ. Light Emitting Diode или просто «LED»)
// Так нам не нужно постоянно вспоминать куда он подключён
#define LED_PIN_1 9
#define LED_PIN_2 11

// значение для уровня яркости светодиодов
#define NO_LIGHT 0
#define START_LIGHT 85
#define MID_LIGHT 170
#define MAX_LIGHT 255

// задаем переменные, которые будут отслеживать
// уровень яркости светодиодов
int led_max = LED_PIN_1;
int led_min = LED_PIN_2;

void setup()
{
  // настраиваем пины со светодиодами в режим выхода,
  // как и раньше
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  // задаем начальный уровень яркости светодиодов
  // выдаём неполное напряжение на светодиод
  // (он же ШИМ-сигнал, он же PWM-сигнал).
  // Микроконтроллер переводит число от 0 до 255 к напряжению
  // от 0 до 5 В. Например, 85 — это 1/3 от 255,
  // т.е. 1/3 от 5 В, т.е. 1,66 В.
  // Больше напряжение — выше яркость!
  analogWrite(led_max, MAX_LIGHT);
  analogWrite(led_min, NO_LIGHT);
}

void loop()
{
  // меняем яркость светодиодов
  // от максимальной яркости до выключения
  // от выключенного состояния до максимальной яркости
  analogWrite(led_max, MAX_LIGHT);
  analogWrite(led_min, NO_LIGHT);
  delay(250);

  analogWrite(led_max, MID_LIGHT);
  analogWrite(led_min, START_LIGHT);
  delay(250);

  analogWrite(led_max, START_LIGHT);
  analogWrite(led_min, MID_LIGHT);
  delay(250);

  analogWrite(led_max, NO_LIGHT);
  analogWrite(led_min, MAX_LIGHT);
  delay(250);

  // меняем местами пины для того,
  // чтобы поменять состояние светодиодов
  if (led_max == LED_PIN_1)
  {
    led_max = LED_PIN_2;
    led_min = LED_PIN_1;
  }
  else
  {
    led_max = LED_PIN_1;
    led_min = LED_PIN_2;
  }
}