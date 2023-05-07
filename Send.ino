#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11
SoftwareSerial P_Serial(6, 7);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
 
  Serial.begin(9600);
  dht.begin();  
  P_Serial.begin(9600);
  pinMode(DHT_PIN, OUTPUT);
  
}

void loop() {
  
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  delay(2000);
  String sensing1 = (String)h;
  String sensing2 = (String)t;
  String str = (String)sensing1 + "#" + (String)sensing2;
  
  Serial.println(str);
  P_Serial.println(str);
}
