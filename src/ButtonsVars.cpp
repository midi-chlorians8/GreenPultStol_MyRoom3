
#include <Arduino.h>
//#include <ButtonsVars.h> // Переменные для обработки кнопки свет комната

#define DownButtonPin 2
#define UpButtonPin 4
#define RightButtonPin 26
#define LeftButtonPin 32
void PinMode(){
  pinMode(UpButtonPin,   INPUT_PULLDOWN); //Верх
  pinMode(DownButtonPin, INPUT_PULLDOWN); //Низ
  pinMode(LeftButtonPin, INPUT_PULLDOWN); //Влево  (Выйти на уровень назад)
  pinMode(RightButtonPin,INPUT_PULLDOWN); //Вправо (Войти в подменю)

  //pinMode(25,OUTPUT); // Буззер выход BUZZER_PIN
}