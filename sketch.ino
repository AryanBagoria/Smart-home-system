#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 8 
#define DHTTYPE 22
DHT dht(DHTPIN, DHTTYPE);

int fanPin = 10;
int pin = 6;
float hum;
float temp;

void setup() 
{
  pinMode(fanPin,OUTPUT);
  pinMode(pin, INPUT);
  Serial.begin(9600);
  dht.begin();
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Date, Time ,PIR motion, temperature, humidity, FAN ");
  Serial.println("RESETTIMER");
}

void loop() 
{
  int state = digitalRead(pin);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("DATA, DATE, TIME,");
  Serial.print(state);
  Serial.print(",");  
  Serial.print(temp);
  Serial.print(",");  
  Serial.print(hum);
      if (state == 1) 
      {
      //Serial.println("Motion Detected!");
        if(temp>26.0)
        {
          digitalWrite(fanPin, HIGH);   // sets the fan on
          //Serial.print("DETECTED");
          Serial.print(" ,");
          Serial.println("ON");
          delay(5000);                  // waits for a 5 second  
         }
       }
     else
     {
      //Serial.println("Motion not Detected!");
      digitalWrite(fanPin, LOW);
      //Serial.print("NOT DETECTED");
      Serial.print(" ,");
      Serial.println("OFF");
      delay(1000);
  }

  
  
}
