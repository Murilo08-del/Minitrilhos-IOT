#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient client;           //Cria objeto p/ wifi
PubSubClient mqtt(client);  //Cria objeto p/ mqtt usando WiFi

const String SSID = "FIESC_IOT_EDU";  //Define o nome da rede
const String PASS = "8120gv08";       //Define a senha da rede

const String brokerURL = "test.mosquitto.org";  // Define o endereço do broker
const int brokerPort = 1883;                  // Define a porta do broker

const String brokerUser = "";  //Variavel para user do broker
const String brokerPass = "";  //Variavel para senha do broker

void setup() {
  Serial.begin(11520);                  // Configura a placa para mostrar a tela
  WiFi.begin(SSID, PASS);               // Tenta conectar na rede
  Serial.println("Conectado no WiFi");  //Enquanto não estiver conectado mostra "."
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.print("Conectado com sucesso!");

  mqtt.setServer(brokerURL.c_str(), brokerPort);  // Configra o servidor do broker / porta
   Serial.println("Conectando no Broker");

  String boardID = "S1-";                  //Cria um nome que começa com "S1"
  boardID += String(random(0xffff), HEX);  // Junta o "S1-" com um número aleatório Hexadecimal
  // Tenta conectar ao Broker
  while (!mqtt.connect(boardID.c_str())) {  // Enquanto não estiver conectado mosta "."
    Serial.print(".");
    delay(200);
  }
  Serial.println("\n Conectado com sucesso ao broker!");
}

void loop() {
  // put your main code here, to run repeatedly:
}
