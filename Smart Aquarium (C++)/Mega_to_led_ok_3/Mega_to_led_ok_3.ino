#include <MemoryFree.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);   

#define trigPin A0
#define echoPin A1
int led_pin_33 = 33;
int led_pin_32 = 32;
int led_pin_31 = 31;
int led_pin_30 = 30;
int led_pin_29 = 29;
int led_pin_28 = 28;
int led_pin_27 = 27;
int led_pin_26 = 26;
int led_pin_25 = 25;
int led_pin_24 = 24;
int led_pin_23 = 23;
int led_pin_22 = 22;
String inString;
String Z = "";
String inip;

void setup() {
   Serial.begin(115200);
  Serial3.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin();
  lcd.backlight();
  lcd.home();
  Serial.print("Welcome To");
  lcd.setCursor(0, 0);                   // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรตำแหน่งที่0 แถวที่ 1 เตรียมพิมพ์ข้อความ
  lcd.print("Welcome To");               //พิมพ์ข้อความ "Welcome To"
  Serial.println("Smart AQUARIUM");
  lcd.setCursor(2, 1);                   // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรกำแหน่งที3 แถวที่ 2 เตรียมพิมพ์ข้อความ
  lcd.print("Smart AQUARIUM");           //พิมพ์ข้อความ "Smart AQUARIUM"
  delay(5000);
  Serial.println("Config your WIFI ");
  lcd.setCursor(0, 0); 
  Serial.println("in:192.168.4.1");
  lcd.print("Config your WIFI "); 
  lcd.setCursor(2, 1); 
  lcd.print("in:192.168.4.1"); 
  delay(5000);
 // Serial.println(Z);
  //Serial.println("Z");
  
  Serial.println("Your IP is :");
  lcd.setCursor(0, 0);
  lcd.print("Your IP is :"); 
  Serial.println(WiFi.localIP());
  lcd.setCursor(2, 1); 
  lcd.print(WiFi.localIP());
  //Serial.println(inip);
  //char localip = Serial.read();
  //Serial.write(localip);
  //inip += localip;
     // if (inip.indexOf("Your IP is :")) {
      //inip = Z;
   //  lcd.begin();
    // lcd.backlight();
    // lcd.home();
     //Serial.print("Your IP is :");
    // lcd.setCursor(0, 0);
    // lcd.print("Your IP is :"); 
   //  lcd.setCursor(2, 1); 
    // Serial.println(Z);
    // Serial.println(inip);
    // lcd.print(Z);
    // lcd.print(inip);
     delay(5000);

     // }
    //  inip = "";
      
  
  pinMode(led_pin_33, OUTPUT);
  digitalWrite(led_pin_33, HIGH);
  pinMode(led_pin_32, OUTPUT);
  digitalWrite(led_pin_32, HIGH);
  pinMode(led_pin_31, OUTPUT);
  digitalWrite(led_pin_31, HIGH);
  pinMode(led_pin_30, OUTPUT);
  digitalWrite(led_pin_30, HIGH);
  pinMode(led_pin_29, OUTPUT);
  digitalWrite(led_pin_29, HIGH);
  pinMode(led_pin_28, OUTPUT);
  digitalWrite(led_pin_28, HIGH);
  pinMode(led_pin_27, OUTPUT);
  digitalWrite(led_pin_27, HIGH);
  pinMode(led_pin_26, OUTPUT);
  digitalWrite(led_pin_26, HIGH);
  pinMode(led_pin_25, OUTPUT);
  digitalWrite(led_pin_25, HIGH);
  pinMode(led_pin_24, OUTPUT);
  digitalWrite(led_pin_24, HIGH);
  pinMode(led_pin_23, OUTPUT);
  digitalWrite(led_pin_23, HIGH);
   pinMode(led_pin_22, OUTPUT);
  digitalWrite(led_pin_22, HIGH);
}

void loop() {
  lcd.begin();
     lcd.backlight();
     lcd.home();
     Serial.println("Your IP is :");
     lcd.setCursor(0, 0);
     lcd.print("Your IP is :");
     Serial.println(WiFi.localIP()); 
     lcd.setCursor(2, 1); 
     lcd.print(WiFi.localIP());
     delay(1000);
   long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  lcd.setCursor(0, 0);
  Serial.println("Distancing");
  lcd.print("Distancing");
  lcd.setCursor(0, 1);
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    lcd.print("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
    lcd.print(distance);
    lcd.print(" cm       ");
  }
  delay(500);
}


void serialEvent3() {
  while (Serial3.available()) {
    char inChar = Serial3.read();
    Serial.write(inChar);
    inString += inChar;
    if (inChar == ']') {
      if (inString.indexOf("[Oxygen=ON]")>0) {
        digitalWrite(led_pin_22, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Oxygen :"); 
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Oxygen=OFF]")>0) {
        digitalWrite(led_pin_22, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Oxygen :"); 
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Filterpump=ON]")>0) {
        digitalWrite(led_pin_23, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Filter pump :"); 
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Filterpump=OFF]")>0) {
        digitalWrite(led_pin_23, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Filter pump :");
        lcd.setCursor(2, 1);
        lcd.print("OFF");
        delay(1000);
      }
      else if (inString.indexOf("[Heater=ON]")>0) {
        digitalWrite(led_pin_24, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Heater :");
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Heater=OFF]")>0) {
        digitalWrite(led_pin_24, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Heater :");
        lcd.setCursor(2, 1); 
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[WaveMaker=ON]")>0) {
        digitalWrite(led_pin_25, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Oxygen :"); 
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[WaveMaker=OFF]")>0) {
        digitalWrite(led_pin_25, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Wave Maker :"); 
        lcd.setCursor(2, 1); 
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[UVLight=ON]")>0) {
        digitalWrite(led_pin_26, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("UV Light :"); 
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[UVLight=OFF]")>0) {
        digitalWrite(led_pin_26, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("UV Light :"); 
        lcd.setCursor(2, 1); 
        lcd.print("OFF");
        delay(1000);
      }
      else if (inString.indexOf("[AquariumLight=ON]")>0) {
        digitalWrite(led_pin_27, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Aquarium Light :"); 
        lcd.setCursor(2, 1); 
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[AquariumLight=OFF]")>0) {
        digitalWrite(led_pin_27, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Aquarium Light :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay1=ON]")>0) {
        digitalWrite(led_pin_28, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 1 :"); 
        lcd.setCursor(2, 1);
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay1=OFF]")>0) {
        digitalWrite(led_pin_28, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 1 :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay2=ON]")>0) {
        digitalWrite(led_pin_29, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 2 :"); 
        lcd.setCursor(2, 1);
        lcd.print("ON");
        delay(1000);
      }
      else if (inString.indexOf("[Relay2=OFF]")>0) {
        digitalWrite(led_pin_29, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 2 :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay3=ON]")>0) {
        digitalWrite(led_pin_30, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 3 :"); 
        lcd.setCursor(2, 1);
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay3=OFF]")>0) {
        digitalWrite(led_pin_30, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 3 :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay4=ON]")>0) {
        digitalWrite(led_pin_31, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 4 :"); 
        lcd.setCursor(2, 1);
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay4=OFF]")>0) {
        digitalWrite(led_pin_31, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 4 :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay5=ON]")>0) {
        digitalWrite(led_pin_32, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 5 :"); 
        lcd.setCursor(2, 1);
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay5=OFF]")>0) {
        digitalWrite(led_pin_32, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 5 :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay6=ON]")>0) {
        digitalWrite(led_pin_33, LOW);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 6 :"); 
        lcd.setCursor(2, 1);
        lcd.print("ON"); 
        delay(1000);
      }
      else if (inString.indexOf("[Relay6=OFF]")>0) {
        digitalWrite(led_pin_33, HIGH);
        LiquidCrystal_I2C lcd(0x27,16,2); 
        lcd.begin();
        lcd.backlight();
        lcd.home();
        lcd.setCursor(0, 0); 
        lcd.print("Relay 6 :"); 
        lcd.setCursor(2, 1);
        lcd.print("OFF"); 
        delay(1000);
      }
 
      else
      {
        Serial.println("Wrong command");
      }
      inString = "";
    }
  }
}
