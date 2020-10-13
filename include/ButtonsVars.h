

// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef ButtonsVars_H
#define ButtonsVars_H



// Параметры кнопки вкл/выкл свет комната
const int buttonPin_RoomLigth = 15;    // the number of the pushbutton pin
bool buttonState_RoomLigth; 
bool ledState_RoomLigth = 0;         // the current state of the output pin
            // the current reading from the input pin
bool lastButtonState_RoomLigth = 0;   // the previous reading from the input pin

unsigned long lastDebounceTime_RoomLigth = 0;  // the last time the output pin was toggled
unsigned long debounceDelay_RoomLigth = 50;    // the debounce time; increase if the output flickers
// Параметры кнопки вкл/выкл свет комната





#endif