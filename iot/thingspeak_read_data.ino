#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

unsigned long counterChannelNumber = **channel_id**;            // Channel ID
const char * myCounterReadAPIKey = **api_key**; // Read API Key
const int FieldNumber1 = 1;  // The field you wish to read
const int FieldNumber2 = 2;  // The field you wish to read
int statusCode;

WiFiClient client;

void setup() 
{
  pinMode(D1, OUTPUT);
  digitalWrite(D1, LOW);
  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to wifi"); 
  WiFi.begin(**your_ssid**, **your_password**);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  ThingSpeak.begin(client);

}

void loop()
{
  long temp = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("Temperature: ");
    Serial.println(temp);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(100);
  long humidity = ThingSpeak.readLongField(counterChannelNumber, FieldNumber2, myCounterReadAPIKey);
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.print("Humidity: ");
    Serial.println(humidity);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(100);
  
  if (temp > 25)
  {
    digitalWrite(D1, HIGH);
  }
  else
  {
    digitalWrite(D1, LOW);
  }
  delay(3000);
  Serial.println("Waiting...");
}
