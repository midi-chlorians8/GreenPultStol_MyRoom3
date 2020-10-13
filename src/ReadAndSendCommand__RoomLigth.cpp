#include <Arduino.h>

#include <ReadAndSendCommand__RoomLigth.h> // Прототип
#include <ButtonsVars.h> // Переменные для обработки кнопки свет комната

//#define PrintDebug
void ReadAndSendCommand__RoomLigth(){
    static int8_t Counter=0;//Чтоб отослать один раз команду на ВКЛ - ВЫКЛ
 
    // Кнопка
    bool reading = digitalRead(buttonPin_RoomLigth);
    #ifdef PrintDebug
    Serial.print("reading:");Serial.print(reading);
    #endif
    if (reading != lastButtonState_RoomLigth) {
      // reset the debouncing timer
      lastDebounceTime_RoomLigth = millis();
    }

    if ((millis() - lastDebounceTime_RoomLigth) > debounceDelay_RoomLigth) {
  
      if (reading != buttonState_RoomLigth) {
        buttonState_RoomLigth = reading;

        if (buttonState_RoomLigth == HIGH) {
          ledState_RoomLigth = !ledState_RoomLigth;
          if(ledState_RoomLigth==1){
            Counter=1;
          }
          else{
            Counter=2;
          }
        
        }
      }
  }



  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState_RoomLigth = reading;
  #ifdef PrintDebug
  Serial.print(" ledState:");Serial.print(ledState_RoomLigth);
  #endif
  // Кнопка
  
  

  if(Counter == 1){
    if(ledState_RoomLigth == true){
     
   for(int i=0;i<25;i++){
     Serial2.println("[Msg:On]");
   }
    }
    Counter=3; //stop transmitt 
  }
  if(Counter ==2){
    if(ledState_RoomLigth == false){
   
      for(int i=0;i<20;i++){
        Serial2.println("[Msg:Off]");
      }
    }
    Counter=3; //stop transmitt
  
  }
  #ifdef PrintDebug
    Serial.print(" Counter:");Serial.println(Counter);
  #endif
}