#include <WiFi.h>
const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

void setup() {
  Serial.begin(11520); // Configura a placa para mostrar a tela 
  WiFi.begin(SSID, PASS); // Tenta conectar na rede 
  Serial.println("Conectado no WiFi");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.print("Conectado com sucesso");

}

void loop() {
  // put your main code here, to run repeatedly:

}
