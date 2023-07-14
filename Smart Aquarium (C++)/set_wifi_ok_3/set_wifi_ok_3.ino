#include <ESP8266WiFi.h>            ////เรียกใช้ library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"        
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
ESP8266WebServer server(80);
MDNSResponder mdns;

String webPage = "";                         
int led_pin_33 = 33;   ////กำหนดตัวแปรให้แต่ละขา
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
String inip;
void handleRoot() {
  server.send(200, "text/html", webPage);
}


void setup() {
  
  Serial.begin(115200);
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  lcd.begin();
  lcd.backlight();
  lcd.home();
  lcd.setCursor(0, 0);                   // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรตำแหน่งที่0 แถวที่ 1 เตรียมพิมพ์ข้อความ
  lcd.print("Welcome To");               //พิมพ์ข้อความ "Welcome To"
  lcd.setCursor(2, 1);                   // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรกำแหน่งที3 แถวที่ 2 เตรียมพิมพ์ข้อความ
  lcd.print("Smart AQUARIUM");           //พิมพ์ข้อความ "Smart AQUARIUM"
  delay(5000);
  lcd.setCursor(0, 0); 
  lcd.print("Config your WIFI "); 
  lcd.setCursor(2, 1); 
  lcd.print("in:192.168.4.1");
  
  WiFiManager wifiManager;               //เรียกใช้คำสั่ง WiFiManager       
  wifiManager.resetSettings();           //เป็นการรีเซ็ตการตั้งค่า WiFi
  wifiManager.autoConnect("Smart Aquarium");       //ตั้งชื่อ wifi 
  Serial.println("connected... :)");
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
  
  
  digitalWrite(led_pin_33, LOW);          //เป็นการตั้งโหมดให้ขา 35 เป็น Output
  pinMode(led_pin_32, OUTPUT);            //เป็นการตั้งค่าให้ขา 35 เป็น LOW 
  digitalWrite(led_pin_32, LOW); 
  pinMode(led_pin_31, OUTPUT);
  digitalWrite(led_pin_31, LOW);
  pinMode(led_pin_30, OUTPUT);
  digitalWrite(led_pin_30, LOW);
  pinMode(led_pin_29, OUTPUT);
  digitalWrite(led_pin_29, LOW);
  pinMode(led_pin_28, OUTPUT);
  digitalWrite(led_pin_28, LOW);
  pinMode(led_pin_27, OUTPUT);
  digitalWrite(led_pin_27, LOW);
  pinMode(led_pin_26, OUTPUT);
  digitalWrite(led_pin_26, LOW);
  pinMode(led_pin_25, OUTPUT);
  digitalWrite(led_pin_25, LOW);
  pinMode(led_pin_24, OUTPUT);
  digitalWrite(led_pin_24, LOW);
  pinMode(led_pin_23, OUTPUT);
  digitalWrite(led_pin_23, LOW);
   pinMode(led_pin_22, OUTPUT);
  digitalWrite(led_pin_22, LOW);
  
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
  Serial.println("");
  Serial.println("ESP8266 board info:");                //แสดงข้อมูลต่างๆของบอร์ด
  Serial.print("\tChip ID: ");
  Serial.println(ESP.getFlashChipId());
  Serial.print("\tCore Version: ");
  Serial.println(ESP.getCoreVersion());
  Serial.print("\tChip Real Size: ");
  Serial.println(ESP.getFlashChipRealSize());
  Serial.print("\tChip Flash Size: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("\tChip Flash Speed: ");
  Serial.println(ESP.getFlashChipSpeed());
  Serial.print("\tChip Speed: ");
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print("\tChip Mode: ");
  Serial.println(ESP.getFlashChipMode());
  Serial.print("\tSketch Size: ");
  Serial.println(ESP.getSketchSize());
  Serial.print("\tSketch Free Space: ");
  Serial.println(ESP.getFreeSketchSpace());


  webPage += "<CENTER><!DOCTYPE html> <html> <body style=\"background-color:powderblue;\"><font color = blue><h1>Welcome to Smart Aquarium</h1></font></CENTER>";    // แสดงบนหน้าเว็บ
  webPage += "</p>";
  webPage += "<p><CENTER>Oxygen<a href=\"/Oxygen=ON\"><button>ON</button></a>&nbsp;<a href=\"Oxygen=OFF\"><button>OFF</button></a></CENTER></p>";                    //สร้างปุ่ม ON และปุ่ม OFF
  webPage += "<p><CENTER>Filter pump<a href=\"/Filterpump=ON\"><button>ON</button></a>&nbsp;<a href=\"Filterpump=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Heater<a href=\"/Heater=ON\"><button>ON</button></a>&nbsp;<a href=\"Heater=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Wave Maker<a href=\"/WaveMaker=ON\"><button>ON</button></a>&nbsp;<a href=\"WaveMaker=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>UV Light<a href=\"/UVLight=ON\"><button>ON</button></a>&nbsp;<a href=\"UVLight=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Aquarium Light<a href=\"/AquariumLight=ON\"><button>ON</button></a>&nbsp;<a href=\"AquariumLight=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Relay 1<a href=\"/Relay1=ON\"><button>ON</button></a>&nbsp;<a href=\"Relay1=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Relay 2<a href=\"/Relay2=ON\"><button>ON</button></a>&nbsp;<a href=\"Relay2=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Relay 3<a href=\"/Relay3=ON\"><button>ON</button></a>&nbsp;<a href=\"Relay3=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Relay 4<a href=\"/Relay4=ON\"><button>ON</button></a>&nbsp;<a href=\"Relay4=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Relay 5<a href=\"/Relay5=ON\"><button>ON</button></a>&nbsp;<a href=\"Relay5=OFF\"><button>OFF</button></a></CENTER></p>";
  webPage += "<p><CENTER>Relay 6<a href=\"/Relay6=ON\"><button>ON</button></a>&nbsp;<a href=\"Relay6=OFF\"><button>OFF</button></a></CENTER></p>";
  Serial.println("");
  Serial.print("Connected to Smart Aquarium ");  
  Serial.print("IP address: ");  
  Serial.println(WiFi.localIP()); //แสดงหมายเลข IP
  String Z = WiFi.localIP().toString();
  Serial.println("Your IP is :"); 
  Serial.println("Z"); 
  inip = "";
  if (inip.indexOf("Your IP is :")) {
     inip = Z; 
     lcd.begin();
     lcd.backlight();
     lcd.home();
     lcd.print(inip);
     lcd.setCursor(0, 0);  
     Serial.println(inip);
    
  }
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
     
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
  
  server.on("/Oxygen=ON", [](){                  //เมื่อหาคำว่า Oxygen=ON เจอ ให้ขา 22 มีสถานะเป็น HIGH
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_22, HIGH);             
    Serial.println("[Oxygen=ON]");
    Serial.println(inip);
    delay(1000);
  });
  
  server.on("/Oxygen=OFF", [](){                  //เมื่อหาคำว่า LED22=OFF เจอ ให้ขา 22 มีสถานะเป็น LOW
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_22, LOW);
    Serial.println("[Oxygen=OFF]");
    delay(1000);
  });
  server.on("/Filterpump=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_23, HIGH);
    Serial.println("[Filterpump=ON]");
    delay(1000);
  });
  
  server.on("/Filterpump=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_23, LOW);
    Serial.println("[Filterpump=OFF]");
    delay(1000);
  });
  server.on("/Heater=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_24, HIGH);
    Serial.println("[Heater=ON]"); 
    delay(1000);
  });
  
  server.on("/Heater=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_24, LOW);
    Serial.println("[Heater=OFF]");
    delay(1000);
  });
  server.on("/WaveMaker=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_25, HIGH);
    Serial.println("[WaveMaker=ON]");
    delay(1000);
  });
  
  server.on("/WaveMaker=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_25, LOW);
    Serial.println("[WaveMaker=OFF]");
    LiquidCrystal_I2C lcd(0x27, 16, 2);
    delay(1000);
  });
  server.on("/UVLight=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_26, HIGH);
    Serial.println("[UVLight=ON]");
    LiquidCrystal_I2C lcd(0x27, 16, 2); 
    delay(1000);
  });
  
  server.on("/UVLight=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_26, LOW);
    Serial.println("[UVLight=OFF]");
    delay(1000);
  });
  server.on("/AquariumLight=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_27, HIGH);
    Serial.println("[AquariumLight=ON]");
    delay(1000);
  });
  
  server.on("/AquariumLight=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_27, LOW);
    Serial.println("[AquariumLight=OFF]");
    delay(1000);
  });
  server.on("/Relay1=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_28, HIGH);
    Serial.println("[Relay1=ON]");
    delay(1000);
  });
  
  server.on("/Relay1=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_28, LOW);
    Serial.println("[Relay1=OFF]");
    delay(1000);
  });
  server.on("/Relay2=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_29, HIGH);
    Serial.println("[Relay2=ON]");
    delay(1000);
  });
  
  server.on("/Relay2=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_29, LOW);
    Serial.println("[Relay2=OFF]");
    delay(1000);
  });
  server.on("/Relay3=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_30, HIGH);
    Serial.println("[Relay3=ON]");
    delay(1000);
  });
  
  server.on("/Relay3=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_30, LOW);
    Serial.println("[Relay3=OFF]");
    delay(1000);
  });
  server.on("/Relay4=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_31, HIGH);
    Serial.println("[Relay4=ON]");
    delay(1000);
  });
  
  server.on("/Relay4=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_31, LOW);
    Serial.println("[Relay4=OFF]");
    delay(1000);
  });
  server.on("/Relay5=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_32, HIGH);
    Serial.println("[Relay5=ON]");
    delay(1000);
  });
  
  server.on("/Relay5=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_32, LOW);
    Serial.println("[Relay5=OFF]");
    delay(1000);
  });
  server.on("/Relay6=ON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_33, HIGH);
    Serial.println("[Relay6=ON]");
    delay(1000);
  });
  
  server.on("/Relay6=OFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin_33, LOW);
    Serial.println("[Relay6=OFF]");
    delay(1000);
  });
  
  server.begin();
  Serial.println("HTTP server started");
  
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
     delay(500);
  server.handleClient();
  
   
}
