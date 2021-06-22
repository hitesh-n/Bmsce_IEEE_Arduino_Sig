#include <ESP8266WiFi.h>

WiFiClient client;

void setup() 
{
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
}

void loop()
{
  if(client.connect("api.thingspeak.com",80))   //   "184.106.153.149" or api.thingspeak.com
  {  
    client.print("GET /update?api_key=JR0NW6QA7T0M0TPK&field1=27&field2=45 HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n");
  }
  client.stop();

  Serial.println("Waiting...");
  delay(10000);
}
