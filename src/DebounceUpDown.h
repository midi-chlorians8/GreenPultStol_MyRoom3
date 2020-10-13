//25.08.2020
#include <Arduino.h>
// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef DebounceV2_H
#define DebounceV2_H

#define UpButtonPin 4
#define DownButtonPin 2

#define RightButtonPin 26
#define LeftButtonPin 32 
void PinMode();     // Вход клавиатуры кнопок

extern int16_t PositionUpCount;
extern int8_t PositionRightCount;
extern int16_t MenuLayer;
extern bool change101;
extern unsigned long timing101;

void DebounceV2(const int8_t buttonPin,bool& buttonState,bool& lastButtonState,
                unsigned long& lastDebounceTime,uint8_t debounceDelay,bool& MinusUP,
                bool& OneRazFirstTimePressed,unsigned long& TimePressed,unsigned long& FirstTimePressed){

  bool reading = digitalRead(buttonPin);
  //static int8_t CountStepTiming;
  if(digitalRead(buttonPin)==1){    
    // Один раз замерять стартовое время
    if(OneRazFirstTimePressed == false){
       FirstTimePressed=millis();
       OneRazFirstTimePressed = true;
    }
    TimePressed=millis();
  }
  else{
    OneRazFirstTimePressed=false; // Если кнопка не нажата 
  }
  // <-

  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
        buttonState = reading;

      if (buttonState == HIGH) {
        
        if(buttonPin == 2){          
             // PositionUpCount++; //Ползунок по вертикали
            MinusUP=false;
            change101=true;timing101 = millis(); // Флаг что кнопка нажата и значение изменилось
        }
        if(buttonPin == 4){
            //if(  (TimePressed-FirstTimePressed) < 500  ){
            //PositionUpCount--; //Ползунок по горизонатали
            MinusUP=false;
            
            //CountStepTim1ing=0;
            change101=true;timing101 = millis();
        }

        
        if(buttonPin == RightButtonPin){
            PositionRightCount++; //Ползунок по горизонатали
        }
        if(buttonPin == LeftButtonPin){
            PositionRightCount--; //Ползунок по горизонатали
        }      
        // Ограничения
            
            PositionRightCount=constrain(PositionRightCount,0,25); //Ограничил щелчки влево. Чуствуется в корне меню
        // Ограничения
        
      }
    }
  }

  // set the LED:
  //digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

// <-
if(digitalRead(buttonPin)==0){
    if(buttonPin == 4 && ( (TimePressed-FirstTimePressed) < 300)  ){
          if(MinusUP == false){
            PositionUpCount-=1;
            MinusUP = true;
            
          }
    }
      //==
    if(buttonPin == 2 && ( (TimePressed-FirstTimePressed) < 300)  ){
          if(MinusUP == false){
            PositionUpCount+=1;
            MinusUP = true;
            //change101=true; // Флаг что кнопка нажата и значение изменилось
          }
    }
}
  //Обработка кнопки вверх
      if(buttonPin == 4 && ( (TimePressed-FirstTimePressed) > 300)  ){
          if(MinusUP == false){
              if(MenuLayer != 0 && MenuLayer != 1 && MenuLayer != 20 && MenuLayer != 21 &&
               MenuLayer != 22 && MenuLayer != 23 && MenuLayer != 10 && MenuLayer != 202 &&
               MenuLayer != 208 && MenuLayer != 2100 && 
               MenuLayer != 10 && MenuLayer != 11 && MenuLayer != 12 && MenuLayer != 13 &&
               MenuLayer != 50  && MenuLayer != 51 && MenuLayer != 52
               ){ // Если на первом уровне и ненадо мотать на + - 10
                  PositionUpCount-=10;
              }       // Если на первом уровне и других ненадо мотать на + - 10
              MinusUP = true;
          }
      }
                    
      
  //Обработка кнопки вверх
   // Serial.print(" PositionUpCount:" );Serial.print( PositionUpCount );
   // Serial.print(" TimePressed Podchet:" );Serial.print( TimePressed-FirstTimePressed );
   // Serial.print(" MinusUP:" );Serial.println( MinusUP );   
    
  //Обработка кнопки вниз 
  ///*
      if(buttonPin == 2 && ( (TimePressed-FirstTimePressed) > 300)  ){
          if(MinusUP == false){
              if(MenuLayer != 0 && MenuLayer != 1 && MenuLayer != 20 && MenuLayer != 21 &&
               MenuLayer != 22 && MenuLayer != 23 && MenuLayer != 10 && MenuLayer != 202 &&
               MenuLayer != 208 && MenuLayer != 210 && 
               MenuLayer != 10 && MenuLayer != 11 && MenuLayer != 12 && MenuLayer != 13 &&
               MenuLayer != 50  && MenuLayer != 51 && MenuLayer != 52
               ){ // Если на первом уровне и других ненадо мотать на + - 10
                  PositionUpCount+=10;
                  MinusUP = true;
              } 
          }
      }                   // Если на первом уровне и ненадо мотать на + - 10
    
  //*/
  //Обработка кнопки вниз

//}
// <-
  // Ограничения
  if(MenuLayer == 20){
    PositionUpCount=constrain(PositionUpCount,100,120);
  }
  //if(MenuLayer == 204){
    //StartToAccel=constrain(StartToAccel,0,99);
  //}
  // Ограничения
}




//Комплект обработки кнопок

bool buttonState4;             // the current reading from the input pin
bool lastButtonState4 = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime4 = 0;  // the last time the output pin was toggled
const uint8_t debounceDelay4 = 5;    // the debounce time; increase if the output flickers

bool MinusUP4 = false;
bool OneRazFirstTimePressed4=false;
unsigned long TimePressed4;
unsigned long FirstTimePressed4;

bool buttonState2;             // the current reading from the input pin
bool lastButtonState2 = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime2 = 0;  // the last time the output pin was toggled
const uint8_t debounceDelay2 = 5;    // the debounce time; increase if the output flickers

bool MinusUP2 = false;
bool OneRazFirstTimePressed2=false;
unsigned long TimePressed2;
unsigned long FirstTimePressed2;

bool buttonState26;             // the current reading from the input pin
bool lastbuttonState26 = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime26 = 0;  // the last time the output pin was toggled
const uint8_t debounceDelay26 = 17;    // the debounce time; increase if the output flickers

bool buttonState32;             // the current reading from the input pin
bool lastbuttonState32 = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime32 = 0;  // the last time the output pin was toggled
const uint8_t debounceDelay32 = 17;    // the debounce time; increase if the output flickers
//Комплект обработки кнопок








// Заканчиваем директивой препроцессора
#endif