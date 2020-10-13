#include <Arduino.h>
// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef DebounceLeftRight_H
#define DebounceLeftRight_H

#define DownButtonPin 2
#define UpButtonPin 4
#define RightButtonPin 26
#define LeftButtonPin 32



// А это уже содержимое заголовочного файла
//int add(int x, int y); // прототип функции add() (не забывайте точку с запятой в конце!)
 void Debounce(const int8_t buttonPin,bool& buttonState,bool& lastButtonState,unsigned long& lastDebounceTime,uint8_t debounceDelay);
 //void DebounceV2(const int8_t buttonPin);

 //void PinMode();
// Заканчиваем директивой препроцессора
#endif


