//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VISITOR COUNTER %%%%%%%%% EMBEDDED SYSTEMS LAB @ TU ILMENAU SS 2021 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#define DETECT_LDR1 A0 // Setting Analog Pin A0 for LDR 1
#define DETECT_LDR2 A1 // Setting Analog Pin A0 for LDR 1

#define speaker 9 // Setting Digital Pin 9 for BUZZER
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // Including I2C Library for our LCD 

LiquidCrystal_I2C lcd(0x27,20,4);  // sets the LCD address to 0x27 for a 16 chars and 2 line display
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Initiazlizing Variables
int count = 0;
int threshold =300;
int i = 0;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// SET NUMBER OF VISITORS ALLOWED
int warning = 2; // For Low Buzzing Sound We can change this
int cuttoff = 5; // For High Buzzing Sound We can change this
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void setup() {
  Serial.begin(9600);
  pinMode(DETECT_LDR1, INPUT);//define detect input pin
  pinMode(DETECT_LDR2, INPUT);//define detect input pin

  
  pinMode(speaker, OUTPUT);   //define BuZZer output pin
  lcd.init();                // initialize the LCD 
  //lcd.init();
  lcd.backlight();
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void loop() {

  int detected_LDR1 = analogRead(DETECT_LDR1);// read Laser sensor
  int detected_LDR2 = analogRead(DETECT_LDR2);// read Laser sensor
  
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Main Algorithm:
// If the Laser is cut first at LDR 1 detected by comparing the change of value with threshold
// This Means A Person Just Entered And the Counter is Increased by 1 else keep the counter value
// 
// If the Laser is cut first at LDR 2 detected and LDR 1 Value is less then Threshold,
// This Means the Person has just Left and Counter is decremented by 1
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  if(detected_LDR2 < threshold && detected_LDR1 > threshold) // Threshold is set using hit and trial method
  {
    Serial.println("Enterance!"); // Serial Outputs only for Testing Purpose
    count = count + 1;
    delay(900);
  }
  else{count = count;}
  if(detected_LDR2 > threshold && detected_LDR1 < threshold)
  {
    
    Serial.println("Departure!");
    count = count - 1;
    delay(900);
  }

  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Setting The Number of Participants that Are Allowed
  // If Visitors increase the Prdefined Number Called (Warning) Buzzer will produce a LIGHT Beeping Sound
  // If Visitors increase the Warning number upto Maximum Number Called (Cuttoff) Buzzer produces Sharp Beeping
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   
  if (count > warning && count < cuttoff){
  //digitalWrite(speaker,HIGH);// set the buzzer ON
  tone(speaker, 4500); // Generating Tone on Buzzer
  delay(50);
  noTone(speaker);
  delay(50);
  }
  else if (count >= cuttoff) {
  tone(speaker, 2500);
  delay(50);
  noTone(speaker);
  delay(50);
  }
  else if (count< warning)
  {digitalWrite(speaker,LOW);}// set the buzzer OFF
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Setting UP LCD
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  lcd.setCursor(0,0);
  lcd.print("Visitor Counter");
  
  lcd.setCursor(0,1);

  lcd.print("Occupancy = ");
  lcd.print(count);
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  

}
 
