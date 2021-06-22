#include <Ubidots.h>

Ubidots ubi_client(**your_token**);

void setup() 
{
  pinMode(D1, OUTPUT);
  digitalWrite(D1, LOW);
  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to wifi"); 
  ubi_client.wifiConnect(**your_ssid**, **your_password**);
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop()
{
  int var = ubi_client.get("iot","button");
  Serial.println("");
  Serial.println(var);
  if (var > 0)
  {
    digitalWrite(D1, HIGH);
  }
  else
  {
    digitalWrite(D1, LOW);
  }
  delay(1000);
}
