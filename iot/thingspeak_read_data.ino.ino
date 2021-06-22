#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

unsigned long counterChannelNumber = 1422581;            // Channel ID
const char * myCounterReadAPIKey = "F1D6MWWVEWBHMPJ1"; // Read API Key
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
  WiFi.begin("ACT102417274243", "Virtualact1@");
  
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

  // https://api.thingspeak.com/update?api_key=JR0NW6QA7T0M0TPK&field1=20&field2=30
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
