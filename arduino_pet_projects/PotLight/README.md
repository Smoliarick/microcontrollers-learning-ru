# Проект "Светильник с управляемой яркостью"

В этом проекте мы меняем яркость светодиода, вращая ручку переменного резистора. Один светодиод будет регулироваться потенциометром, а второй будет иметь яркость, равную 1/8 от яркости первого светодиода.

## Список деталей для проекта

- 1 плата [Arduino Uno R3](../../articles/ArduinoComponents.md#arduino-uno-r3)
- 1 беспаечная [макетная плата](../../articles/ArduinoComponents.md#макетная-плата---breadboard-half)
- 2 [светодиода](../../articles/ArduinoComponents.md#светодиоды-5-мм---5-mm-led)
- 2 [резистора номиналом 220 Ом](../../articles/ArduinoComponents.md#резистор-220-ом---resistor-220-ω)
- 8 [проводов "папа-папа"](../../articles/ArduinoComponents.md#провод-папа-папа---wire-dad-dad)
- 1 [потенциометер](../../articles/ArduinoComponents.md#потенциометер---potentiometer)

## Схема на макетной плате

<img src="PotLight_МП.png" alt="Схема на макетной плате" width="50%"/>

[Схема для приложения Fritzing](PotLight.fzz)

## Код для Arduino

[PotLight.ino](PotLight.ino):

```c
// даём разумные имена для пинов со светодиодом
// и потенциометром (англ potentiometer или просто «pot»)
#define LED_PIN_1 9
#define LED_PIN_2 5
#define POT_PIN A0

void setup()
{
  // пин со светодиодом — выход, как и раньше...
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  // ...а вот пин с потенциометром должен быть входом
  // (англ. «input»): мы хотим считывать напряжение,
  // выдаваемое им
  pinMode(POT_PIN, INPUT);
}

void loop()
{
  // заявляем, что далее мы будем использовать 2 переменные с
  // именами rotation и brightness, и что хранить в них будем
  // целые числа
  int rotation, brightness_pin_1, brightness_pin_2;

  // считываем в rotation напряжение с потенциометра:
  // микроконтроллер выдаст число от 0 до 1023
  // пропорциональное углу поворота ручки
  rotation = analogRead(POT_PIN);

  // в brightness записываем полученное ранее значение rotation
  // делённое на 4. Поскольку в переменных мы пожелали хранить
  // целые значения, дробная часть от деления будет отброшена.
  // В итоге мы получим целое число от 0 до 255
  brightness_pin_1 = rotation / 4;
  brightness_pin_2 = rotation / 32;

  // выдаём результат на светодиод
  analogWrite(LED_PIN_1, brightness_pin_1);
  analogWrite(LED_PIN_2, brightness_pin_2);
}
```

## Результат

![PotLight](PotLight.gif)