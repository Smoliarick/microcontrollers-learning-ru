<h1>Полезная информация об Arduino и список pet проектов</h1>

<h1>Содержание</h1>

- [Работа с программами для Arduino в VS Code](#работа-с-программами-для-arduino-в-vs-code)
- [Список Pet проектов](#список-pet-проектов)
- [Полезная информация](#полезная-информация)
  - [Приложения](#приложения)
  - [Информация](#информация)

# Работа с программами для Arduino в VS Code

1. Устанавливаем компилятор для C/C++ через [MSYS2](https://www.msys2.org/)
2. Устанавливаем [Arduino CLI](https://arduino.github.io/arduino-cli/0.35/installation/)
3. Распаковываем Aruino CLI и добавляем в PATH для Windows
4. Устанавливаем [Visual Studio Code](https://code.visualstudio.com/)
5. Устанавливаем [pасширение для работы с C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools&ssr=false#review-details)
6. Если все настроено правильно, то VS Code создаст файл `.vscode/c_cpp_properties.json`
7. Устанавливаем [расширение для работы с Arduino](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino&ssr=false#review-details) в Visual Studio Code
8. В настройках расширения включаем: Arduino: Use Arduino CLI
9. Открываем Arduino Board Manager и выбираем нужные настройки для вашего микроконтроллера (CTRL + Shift + P -> вводим Arduino: Board Manager)
10. Выбираем ваш микроконтроллер (CTRL + Shift + P -> вводим Arduino: Change Board Type -> Выбираем Arduino UNO (если вы его используете))
11. Подсоединяем Arduino к компьютеру через USB
12. Выбираем программатор (CTRL + Shift + P -> вводим Arduino: Select Programmer -> AVR ISP - для Arduino Uno)
13. Выбираем порт для загрузки кода на Arduino (CTRL + Shift + P -> вводим Arduino: Select Serial Port -> у меня был COM5 (Устройство с последовательным интерфейсом USB))
14. В результате должен быть файл `.vscode/arduino.json`, например:

```json
{
    "board": "arduino:avr:uno",
    "sketch": "arduino_pet_projects\\Blink\\Blink.ino",
    "programmer": "avrisp",
    "port": "COM5"
}
```

15. Создаем код с расширением `.ino`. Примеры можно найти в [папке с pet проектами](../arduino_pet_projects/)
16. Если код выдает ошибки в файле (что какие-то функции или переменные не найдены), то в файле `c_cpp_properties.json` нужно оставить профиль только для `Arduino`
17. В правом верхнем углу VS Code должна появиться панелька для верифаинга файлов и загрузки в Arduino

<img src="../img/Arduino/ArduinoExtensionPanel.png" alt="Панель Arduino"/>

18. Нажимаем кнопку Arduino: Verify (CTRL + ALT + R), если все норм, то вы не увидите ошибок в консоли. Примерно такой вывод:

```
[Starting] Verifying sketch 'arduino_pet_projects\Blink\Blink.ino'
[Warning] Output path is not specified. Unable to reuse previously compiled files. Build will be slower. See README.
IntelliSense configuration already up to date. To manually rebuild your IntelliSense configuration run "Ctrl+Alt+I"
[Done] Verifying sketch 'arduino_pet_projects\Blink\Blink.ino'
```

19. Далее собираем проект на макетной плате и загружайте программу в Arduino. Нажмите кнопку Arduino: Upload (CTRL + ALT + U). После загрузки вы увидите длинное сообщение с информацией. Пример:

```
[Starting] Uploading sketch 'arduino_pet_projects\Blink\Blink.ino'
[Warning] Output path is not specified. Unable to reuse previously compiled files. Build will be slower. See README.
avrdude: Version 6.3-20190619
...другая информация
[Done] Uploading sketch 'arduino_pet_projects\Blink\Blink.ino'
```

20. Далее перезагрузите Arduino кнопкой Reset (если программа сразу не загрузилась) и посмотрите на свой результат

# Список Pet проектов

- [Маячок](../arduino_pet_projects/Blink/) - в этом проекте мы просто мигаем светодиодом.

# Полезная информация
## Приложения

- Приложение [Fritzing](https://fritzing.org/) - свободное кроссплатформенное программное обеспечение, упрощённый САПР с WYSIWYG-интерфейсом для хоббийных проектов экосистемы Arduino: [Версия 0.9.9.64](../files/Fritzing-0.9.9.64.pc-Compiled-Build-main.zip) 
- Приложение [Visual Studio Code](https://code.visualstudio.com/) -  текстовый редактор, разработанный Microsoft для Windows, Linux и macOS. Позиционируется как "лёгкий" редактор кода для кроссплатформенной разработки веб- и облачных приложений. Включает в себя отладчик, инструменты для работы с Git, подсветку синтаксиса, IntelliSense и средства для рефакторинга. Также есть много полезных расширений для разработки.
- [Arduino](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino&ssr=false#review-details) расширение для Visual Studio Code для работы с Arduino
- [Arduino IDE](https://www.arduino.cc/en/software) - интегрированная среда разработки для Windows, MacOS и Linux, разработанная на Си и C++, предназначенная для создания и загрузки программ на Arduino-совместимые платы, а также на платы других производителей.

## Информация

- [Основы работы с Arduino от Амперка](http://wiki.amperka.ru/%D0%BA%D0%BE%D0%BD%D1%81%D0%BF%D0%B5%D0%BA%D1%82-arduino)