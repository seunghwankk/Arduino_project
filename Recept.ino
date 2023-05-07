#include <Servo.h> 
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>             
#include <SoftwareSerial.h> 

SoftwareSerial P_Serial(6, 7); 
LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo servo;                        
volatile byte state = LOW;          
unsigned long pre_time = 0;         
unsigned long cur_time = 0;         

char str[20];    
char *sArr[4];   

void setup() {  
  
  pinMode(2, INPUT);    
  pinMode(3, OUTPUT);   
  attachInterrupt(0, buttonClick, RISING);  
  digitalWrite(3, HIGH);   
  servo.attach(3);         
  
  Serial.begin(9600);      
  P_Serial.begin(9600);    
  lcd.init();              
  lcd.backlight();         
  lcd.setCursor(0,0);      
  lcd.setCursor(0,1);     
  delay(2000);
  lcd.clear();            
}

void loop() {               
  
  int index = 0, i = 0;    
  char * ptr = NULL;       
  
  while(P_Serial.available())
  {
    str[index++] = P_Serial.read(); 
  }
  str[index] = '\0';

  ptr = strtok(str, "#");

  while(ptr != NULL)
  {
    sArr[i++] = ptr;
    ptr = strtok(NULL, " ");
  }
  int a = atoi(sArr[0]);
  int b = atoi(sArr[1]);
  
  lcd.setCursor(0,0);      
  lcd.print("humi: ");     
  lcd.print(a);            
  lcd.print(" % ");        
  lcd.setCursor(0,1);       
  lcd.print("temp: ");     
  lcd.print(b);            
  lcd.print(" C ");

  if(a == 0)       
  {
    servo.write(0);
    delay(10);
  } 
  else if(a < 30)      
  {
    for(int j = -60; j < 60; j++)       
    {
      servo.write(abs(j));
      delay(10);
    }
  }
  else
  {
    for(int k = -90; k < 90; k++)
    {
      servo.write(abs(k));
      delay(10);
    }
  }

        
  Serial.println(a);      
  Serial.println(b);
  delay(10000);
}

void buttonClick()       
{
  if(state==false){       
    servo.write(180);       
    state=true;      
  }else{       
    servo.write(0);       
    state=false;       
  }
  
  cur_time = millis();       
  if(cur_time - pre_time >= 1000)       
  {
    pre_time = cur_time;      
  }
}