#include <ESP8266WiFi.h>

const char *ssid = "PIFer"; 
const char *password = "payitforward"; 

IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

int port = 8888;  //Port number
WiFiServer server(port);

int cnt = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while(client.connected()){      
      while(client.available()>0){
        // read data from the connected client
        Serial.write(client.read());
        digitalWrite(LED_BUILTIN, LOW);
      }
      while(Serial.available()>0)
      {
        //Send Data to connected client
        client.write(Serial.read());
        digitalWrite(LED_BUILTIN, LOW);
      }
      cnt++;
      if(cnt%500==0) digitalWrite(LED_BUILTIN, HIGH);
    }
    client.stop();
  }
}
