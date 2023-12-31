#define LED_PIN_1 9
#define LED_PIN_2 11

#define NO_LIGHT 0
#define START_LIGHT 85
#define MID_LIGHT 170
#define MAX_LIGHT 255

int led_max = LED_PIN_1;
int led_min = LED_PIN_2;

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  analogWrite(led_max, MAX_LIGHT);
  analogWrite(led_min, NO_LIGHT);
}

void loop()
{
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