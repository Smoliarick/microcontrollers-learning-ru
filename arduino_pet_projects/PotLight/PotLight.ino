#define LED_PIN_1 9
#define LED_PIN_2 5
#define POT_PIN A0

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop()
{
  int rotation, brightness_pin_1, brightness_pin_2;

  rotation = analogRead(POT_PIN);
  brightness_pin_1 = rotation / 4;
  brightness_pin_2 = rotation / 32;

  analogWrite(LED_PIN_1, brightness_pin_1);
  analogWrite(LED_PIN_2, brightness_pin_2);
}