#include <ESP8266WiFi.h>

WiFiClient client;

void setup() 
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to wifi"); 
  WiFi.begin("**your_ssid**", "**your_password**");
  
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
  if(client.connect("api.pushingbox.com",80))   //   "184.106.153.149" or api.thingspeak.com
  {  
    client.print("GET /pushingbox?devid=" + **your_device_id** + "&id=Sheet1&name=hi HTTP/1.1\r\nHost: api.pushingbox.com\r\nConnection: close\r\n\r\n");
  }
  client.stop();

  Serial.println("Waiting...");
  delay(10000);
}
