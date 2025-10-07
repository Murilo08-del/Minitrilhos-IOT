#include <WiFi.h>
#include<PubSubClient.h>

WiFiClient client;          //cria objeto p/wifi
PubSubClient mqtt(client);  //cria objeto p/ mqtt usando wifi
const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

const String brokerURL = "test.mosquitto.org";
const int brokerPort = 1833;

const String brokerUser = "";
const String brokerPass = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASS);
    Serial.println("Conectando no WiFi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
    
  }
  Serial.println("Conectado com sucesso");

  mqtt.setServer(brokerURL.c_str(),brokerPort);
  Serial.println("Conectando no Broker");

  //cria o nome que começa com "S2-"
  String boardID = "S2-";

//junta o "S2-"com um numero aleatória hexadecimal
  boardID += String(random(0xffff),HEX);

  while(!mqtt.connect(boardID.c_str())){
    Serial.print(".");
    delay(200);
  }
  Serial.println("\nConectado com sucesso ao broker!");
}

void loop() {
  

}
