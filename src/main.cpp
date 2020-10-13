// 13.10.2020 Романовский И С. Зелёный пульт на стол. Код для Esp32. Меню. Отдельная кнопка ВКЛ/ВЫКЛ свет в комнате. Чтение 4х кнопок.

#include <Arduino.h>

#include <ReadAndSendCommand__RoomLigth.h> //Чтение кнопки и отсылка команды на свет 

#include <DrawDisplay.h> //Отрисовка картинки на дисплее

//#include <ButtonsVars.h> // Переменные для обработки кнопки свет комната
#include "DebounceUpDown.h"      // Обработка вертикальных кнопок
#include "DebounceLeftRight.h"    // Обработка вертикальных кнопок


void GlobalPrint();
void MenuData();
//#include "GlobalPrint.h"

// Переменные используемые поворотниками
bool change101 = false; // Флаг что кнопка нажата и значение изменилось
unsigned long timing101;  //для задержки в 500 мсек в 1.1 (101)
// Переменные используемые поворотниками

// Переменные которые мы изменяем из меню. Которые и влияют на работу системы
bool DrawPovorotniki = false; // 4.1
bool ActivateDayLight = false; // 5.1
// Переменные которые мы изменяем из меню. Которые и влияют на работу системы
void setup() {
  Serial.begin(115200); // Debug

  // Send 433 Light
    Serial2.begin(4800,SERIAL_8N1,16,17);//rx tx
  // Send 433 Light

  // Кнопка
    pinMode(15, INPUT_PULLDOWN); //const int buttonPin_RoomLigth;
    PinMode();// Вход клавиатуры кнопок
  // Кнопка

  DisplayInit(); //Прописываем тип дисплея,модель. Тип соединения и пины.
}


void loop() {
  ReadAndSendCommand__RoomLigth(); // Чтение сост кнопки [СВЕТ КОМНАТА].  Отправка команды на вкл-выкл света при нажатии на кнопку
  
  MenuData();
  DrawDisplay();

  DebounceV2(UpButtonPin,buttonState4,lastButtonState4,lastDebounceTime4,debounceDelay4,MinusUP4,OneRazFirstTimePressed4,TimePressed4,FirstTimePressed4);//Обработка нажатия вверх +
  DebounceV2(DownButtonPin,buttonState2,lastButtonState2,lastDebounceTime2,debounceDelay2,MinusUP2,OneRazFirstTimePressed2,TimePressed2,FirstTimePressed2);

  Debounce(RightButtonPin,buttonState26,lastbuttonState26,lastDebounceTime26,debounceDelay26);//Обработка нажатия вверх
  Debounce(LeftButtonPin, buttonState32,lastbuttonState32,lastDebounceTime32,debounceDelay32);//Обработка нажатия вверх

  GlobalPrint();
}


//extern int8_t CountBlinkOnIntModeR;
void GlobalPrint(){

Serial.print(" MenuLayer:" );Serial.print(MenuLayer );
Serial.print(" PositionUpCount:" );   Serial.print(PositionUpCount );


Serial.print(" PositionRightCount:" );Serial.print(PositionRightCount );
    /*
Serial.print(" saveBlink3_1:" );Serial.print(saveBlink3_1 );

Serial.print(" OldPositionRightCount(Auto):" );   Serial.print(OldPositionRightCount );

//Serial.print(" OldPositionRightCount:" );Serial.print(OldPositionRightCount);
Serial.print(" OldPositionRightCountInt:" );Serial.print(OldPositionRightCountInt);
*/
//Serial.print(" AutomaticModeActivateR:" );Serial.print(AutomaticModeActivateR ); 
//Serial.print(" PovorotOnRight:" );Serial.print(PovorotOnRight);
 //Serial.print(" CountBlinkOnIntModeR:" );Serial.print(CountBlinkOnIntModeR);
//Serial.print(" OnSound:" );Serial.print(OnSound );

//Serial.print(" BrightnessDayLight" );Serial.print(BrightnessDayLight );

//Serial.print(" BrightnessInEcoMode255:" );Serial.print(BrightnessInEcoMode255); //L -1 ;B - 0;
//Serial.print(" TactPovorotnikiToLightOrBeep:" );Serial.print(TactPovorotnikiToLightOrBeep);
Serial.println();
// Serial.print(" AftherOn:" );Serial.print(AftherOn);
//Serial.print(" Perebor:" );Serial.print(Perebor ); 
/*


Serial.print(" beginIntModeBlinkL:" );Serial.print(beginIntModeBlinkL );
*/
//Serial.println();
}


extern bool OneRazMLayerMin1;
extern unsigned long FirstZamerMLayerMin1_Val;
extern int CirclY;
void MenuData(){
  // Главный экран
  if(MenuLayer==-1){
    // Обработка входа в главное меню
      if( (digitalRead(RightButtonPin)==HIGH) && (digitalRead(LeftButtonPin)==HIGH) ){ //Если нажаты левая и правая кнопки одновременно

          // Один раз замерять текущее время
          if(OneRazMLayerMin1 == false){ FirstZamerMLayerMin1_Val = millis();OneRazMLayerMin1 = true;}
          // Один раз замерять текущее время

          // Если текущее время - замерянное больше 2х секунд. То войти в меню 
          if(millis() - FirstZamerMLayerMin1_Val >1200){
              MenuLayer=0;PositionUpCount=1;PositionRightCount=0; // Войти в меню
              // OffPovorotniki = true; //Выставить флаг погасить поворотник при входе в меню
          }
          // Если текущее время - замерянное больше 2х секунд. То войти в меню
      }
      else{OneRazMLayerMin1=false;} 
    // Обработка входа в главное меню
    
  }
  // Главный экран

  // Ползаем по главному меню
if(MenuLayer==0 || MenuLayer==1){
  //RightInt=false; // Cкидываем чтоб после того как выходим из меню в главный экран не включался правый поворотник
  if(ActivateDayLight!=1){ // Если не включён режим day light (чтоб не было мерцания)
    //PovorotnikiRightOff(); PovorotnikiLeftOff();           //Защита от загорания при переходе в главное меню из int mode
  }
  //beginIntModeBlinkR = false; beginIntModeBlinkL = false;//Защита от загорания при переходе в главное меню из int mode
  
  //PovorotOnRight=false; // Чтоб при выходе из меню в главный экран не загорался поворотник
  if(PositionUpCount == 0){PositionUpCount = 7;} // Ограничить вертикальный ползунок при движении вверх
  if(PositionUpCount > 7){PositionUpCount = 7;} // Ограничить вертикальный ползунок при движении вниз

  if(PositionUpCount==1){   CirclY = 18; //MenuLayer=0;  
                            if( PositionRightCount == 1){ MenuLayer=10;  PositionUpCount=50; } 
  }
  if(PositionUpCount==2){   CirclY = 29; //MenuLayer=0; 
                            if( PositionRightCount == 1){ MenuLayer=20;  PositionUpCount=100; } 
                        }                   
  if(PositionUpCount==3){   CirclY = 39; //MenuLayer=0;
                            if( PositionRightCount == 1){ MenuLayer=30;  PositionUpCount=100; }
                        }
  if(PositionUpCount==4){   CirclY = 48; MenuLayer=0;  
                            if(PositionRightCount == 1) { MenuLayer = 40;PositionUpCount=1; } 
                        }
  if(PositionUpCount==5){   CirclY = 8;  MenuLayer=1;  
                            if(PositionRightCount == 1) {MenuLayer = 50;PositionUpCount=100;} 
                        }
  if(PositionUpCount==6){   CirclY = 18; MenuLayer=1;  
                            if(PositionRightCount == 1) {PositionRightCount=0;} // Заглушка
                        }
  if(PositionUpCount==7){   CirclY = 28; MenuLayer=1;  // exit
                            if( PositionRightCount == 1){ // Если мы жмякаем в правую сторону на exit
                              MenuLayer=-1; 
                              //OffPovorotniki = true; 
                              //timingOffPovorotniki=millis(); 
                              //PovorotOnRight=true;
                              //PositionRightCount = OldPositionRightCountInt; // Чтоб убрать баги с морганием при выходе из меню интеллигент режим
                            } // Выключить поворотники при выходе из меню
                            if( PositionRightCount == -1){ // Если мы жмякаем в левую сторону на exit 
                              MenuLayer=-1;
                              // OffPovorotniki = true; timingOffPovorotniki=millis(); 
                              //PovorotOnRight=true;
                              //PositionRightCount = OldPositionRightCountInt; // Чтоб убрать баги с морганием при выходе из меню интеллигент режим
                            } // Выключить поворотники при выходе из меню
                        }
                         
  
}
// Ползаем по главному меню
}