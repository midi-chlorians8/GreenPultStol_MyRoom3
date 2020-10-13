#include <DrawDisplay.h> 
// Блок экран
#include <U8g2lib.h>

  #ifdef U8X8_HAVE_HW_SPI
  #include <SPI.h>
  #endif
  //U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0,  22, 21,  12,  14, 23); (U8G2_R0, /* clock=*/ 22, /* data=*/ 21, /* cs=*/ 12, /* dc=*/ 14, /* reset=*/ 23);
  U8G2_SSD1309_128X64_NONAME0_F_4W_SW_SPI u8g2(U8G2_R0,  22, 21,  12,  14, 23);
// Блок экран


void DisplayInit(){
  // Блок экран
    u8g2.begin();
    u8g2.setFont(u8g2_font_6x10_tr);
  // Блок экран
}

#include "MenuVariables_PrototypeFunc.h" //Переменные для работы меню и Прототипы функий SaveBlink
extern bool DrawPovorotniki;

void DrawDisplay(){  // oled 2.42 ssd 1309

      if (MenuLayer == -1){ // Отрисовка поворотника + Писк
          u8g2.clearBuffer();          // clear the internal memory   
      
      

          if(DrawPovorotniki==false){
            u8g2.setFont(u8g2_font_7x14B_tr);	
            u8g2.drawStr(20, 35-3, "Glavnij Ekran");  //u8g2.drawStr(35+10, 40-3, "Off");
          }
          if(DrawPovorotniki == true){ // Если включена отрисовка поворотников то рисуем стрелочки
          
          // Проигрывание звука вызванного работой поворотников
        
          }
          u8g2.sendBuffer();          // transfer internal memory to the display
      }
       if (MenuLayer == 0 ) {
          u8g2.clearBuffer();          // clear the internal memory
          u8g2.setFont(u8g2_font_6x12_tr);
          u8g2.drawStr(45, 7, " MENU"); // write something to the internal memory
          u8g2.drawStr(5, 25-3, "1 Povorotniki"); // write something to the internal memory
          u8g2.drawStr(5, 35-3, "2 Passing lights"); // write something to the internal memory
          u8g2.drawStr(5, 45-3, "3 Buzzer");
          u8g2.drawStr(5, 55-3, "4 Glavnij Ecran"); // write something to the internal memory
          u8g2.drawTriangle(110+20,CirclY-5, 95+20,CirclY, 110+20,CirclY+5); 
          u8g2.sendBuffer();          // transfer internal memory to the display
       }
      if (MenuLayer == 1 ) {
          u8g2.clearBuffer();          // clear the internal memory
          u8g2.setFont(u8g2_font_6x12_tr);
          
          u8g2.drawStr(5, 10,   "5 Dimensions"); // write something to the internal memory
          u8g2.drawStr(5, 25-3, "6 Punkt menu");// write something to the internal memory
          u8g2.drawStr(5, 35-3, "Exit ");
          u8g2.drawTriangle(110+20,CirclY-5, 95+20,CirclY, 110+20,CirclY+5);  
          u8g2.sendBuffer();          // transfer internal memory to the display
      }

}
/*
  u8g2.setDisplayRotation(U8G2_R0);
  u8g2.setFlipMode(0);
  u8g2.drawStr(2,15,"Hello World Minecraft!");    
     
  u8g2.drawFrame(0,0,u8g2.getDisplayWidth(),u8g2.getDisplayHeight() );

  u8g2.drawStr(2, 45, u8x8_u16toa(u8g2.getDisplayWidth(), 5));
  u8g2.drawStr(2, 60, u8x8_u16toa(u8g2.getDisplayHeight(), 5));
  u8g2.sendBuffer(); 
  */
 // Отрисовка меню



//  /*








//u8g2.clearDisplay();
 






 
    /*










      if (MenuLayer == -1){ // Отрисовка поворотника + Писк
          u8g2.clearBuffer();          // clear the internal memory   
      
      

          if(DrawPovorotniki==false){
            u8g2.setFont(u8g2_font_7x14B_tr);	
            u8g2.drawStr(20, 35-3, "Glavnij Ekran");  //u8g2.drawStr(35+10, 40-3, "Off");
          }
          if(DrawPovorotniki == true){ // Если включена отрисовка поворотников то рисуем стрелочки
          
          // Проигрывание звука вызванного работой поворотников
        
          }
          u8g2.sendBuffer();          // transfer internal memory to the display
      }













  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R0,F1");

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R1);
  u8g2.setFlipMode(0);
  draw("R1,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R1,F1");

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R2);
  u8g2.setFlipMode(0);
  draw("R2,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R2,F1");

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R3);
  u8g2.setFlipMode(0);
  draw("R3,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R3,F1");
 */

  