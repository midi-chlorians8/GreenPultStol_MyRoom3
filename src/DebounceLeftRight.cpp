#include <Arduino.h>
extern int16_t PositionUpCount;
extern int8_t PositionRightCount;
extern int8_t MenuLayer;
#define RightButtonPin 26
#define LeftButtonPin 32
#define UpButtonPin 4
#define DownButtonPin 2



extern bool DoubleL;
extern int8_t OldPositionRightCount;
void Debounce(const int8_t buttonPin,bool& buttonState,bool& lastButtonState,unsigned long& lastDebounceTime,uint8_t debounceDelay){
  bool reading = digitalRead(buttonPin);


  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
        buttonState = reading;


      if (buttonState == HIGH) {
        
//        ledState = !ledState;
/*
        if(buttonPin == 2){          
             // PositionUpCount++; //Ползунок по вертикали
            MinusUP=false;
        }
        if(buttonPin == 4){
            //if(  (TimePressed-FirstTimePressed) < 500  ){
            //PositionUpCount--; //Ползунок по горизонатали
            MinusUP=false;
        }
*/
        
        if(buttonPin == RightButtonPin){
            
                PositionRightCount++; //Ползунок по горизонатали
            
        }

        if(buttonPin == LeftButtonPin){
            //if(MenuLayer != -1){
                PositionRightCount--; //Ползунок по горизонатали
            //} PositionRightCount = OldPositionRightCount
        }      
        // Ограничения
          if(MenuLayer!= -1){  
              if( (PositionUpCount !=7 && MenuLayer ==0) || (PositionUpCount !=7 && MenuLayer ==1)  ){ // Если курсор не на строке exit
                PositionRightCount=constrain(PositionRightCount,0,25); //Ограничил щелчки влево. Чуствуется в корне меню
              }                        // Если курсор не на строке exit
          }
        // Ограничения
        
      }
    }
  }

  // set the LED:
  //digitalWrite(ledPin, ledState);
  

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

}
// <-
/*
if(digitalRead(buttonPin)==0){
  if( TimePressed-FirstTimePressed >0){
    Serial.print(" PositionUpCount:" );Serial.print( PositionUpCount );
    Serial.print(" TimePressed Podchet:" );Serial.print( TimePressed-FirstTimePressed );
    Serial.print(" MinusUP:" );Serial.println( MinusUP );
  }
  
  //Обработка кнопки вверх
  if(buttonPin == 4 && ( (TimePressed-FirstTimePressed) > 300)  ){
      if(MinusUP == false){
        PositionUpCount-=10;
        MinusUP = true;
      }
  }
  if(buttonPin == 4 && ( (TimePressed-FirstTimePressed) < 300)  ){
      if(MinusUP == false){
        PositionUpCount-=1;
        MinusUP = true;
      }
  }
  //Обработка кнопки вверх
  */
  //Обработка кнопки вниз 
  /*
  if(buttonPin == 2 && ( (TimePressed-FirstTimePressed) > 300)  ){
      if(MinusUP == false){
        PositionUpCount+=10;
        MinusUP = true;
      }
  }
  if(buttonPin == 2 && ( (TimePressed-FirstTimePressed) < 300)  ){
      if(MinusUP == false){
        PositionUpCount+=1;
        MinusUP = true;
      }
  }
  */
  //Обработка кнопки вниз


// <-


