// @author : fajarlabs

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int dataSerial = 0;

int LED = 13;
void setup() { 
  lcd.begin();
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite (LED, HIGH);
  Serial.println("Halo, ini adalah pesan dari arduino!");
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("PINTU I (CAM 1)");
  lcd.setCursor(0,1);
  lcd.print(">> TUTUP");
  
  while (Serial.available()) {
    dataSerial = Serial.read();
  }
  if (dataSerial == '1') {
    clearLCDLine(1);
    lcd.print(">> BUKA");
    digitalWrite(LED, LOW); // sets the LED on
    delay(1000); 
  }

  if (dataSerial == '0'){
    clearLCDLine(1);
    lcd.print(">> TUTUP");
    digitalWrite(LED, HIGH);  // sets the LED off
    delay(1000);                // waits for a second
    dataSerial = 0;
  }
}

void clearLCDLine(int line){
 for(int n = 0; n < 20; n++) { // 20 indicates symbols in line. For 2x16 LCD write - 16
   lcd.setCursor(n,line);
   lcd.print(" ");
 }
 lcd.setCursor(0,line); // set cursor in the beginning of deleted line
}
