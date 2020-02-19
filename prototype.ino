#include <LiquidCrystal.h>
//projet de fin de session / test de base des composants, prototype arduino..

LiquidCrystal lcd(7, 6, 8, 5, 10, 11);
volatile int sortie = LOW;    
const int pinbuzzer = 12;                  
int i = 0;   

void buttonPressed1()           //ISR function excutes when push button at pinD2 is pressed
{                    
   sortie = LOW;                //Change Output value to LOW                                
   lcd.setCursor(0,1);                                          
   lcd.print("Interrupt 1");
    noTone(pinbuzzer);
}

void buttonPressed2()           //ISR function excutes when push button at pinD3 is pressed                             
{                    
   sortie = HIGH;               //Change Output value to HIGH                                    
   lcd.setCursor(0,
   1);                                          
   lcd.print("Interrupt2");
   tone(pinbuzzer, 1000);
}

void setup()
{
  pinMode(2, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT);
  pinMode(3, INPUT_PULLUP);
  
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);   
                                            
  lcd.begin(16,2);                              //  setting LCD as 16x2 type
  lcd.setCursor(0,0);
  lcd.print("CIRCUIT AVEC INTERRUPT");                                    
  lcd.setCursor(0,1);
  lcd.print("Arduino Interrupt");
  delay(3000);                                                     
  lcd.clear();

  attachInterrupt(digitalPinToInterrupt(2),buttonPressed1,RISING);  //  function for creating external interrupts at pin2 on Rising (LOW to HIGH)
  attachInterrupt(digitalPinToInterrupt(3),buttonPressed2,RISING);  //  function for creating external interrupts at pin3 on Rising (LOW to HIGH)                                                                                          
}

void loop()
{ 
   lcd.clear();                                                   
   lcd.print("COUNTER:");                                           
   lcd.print(i);                                                  
   ++i;                                                            
   delay(1000);   
   digitalWrite(13,sortie);     //Turns LED ON or OFF depending upon sortie value
}
