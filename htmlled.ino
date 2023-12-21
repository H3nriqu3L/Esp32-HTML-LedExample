#include "M5Atom.h"
#include <WiFi.h>

const char* mySSID = "WifiName";
const char* myPassword = "WifiPassword";

boolean myStatusOUT1 = HIGH;
WiFiServer myServer(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(mySSID, myPassword);

  Serial.print("Conectando ao WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Conectado ao WiFi");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  myServer.begin();
}

void loop() {

  WiFiClient client = myServer.available();
  if (!client) {
    //Serial.println("Server Indisponivel");
    return;
  }
  
  Serial.println("connect");
  while (!client.available()) {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // A partir daqui verifica qual botão foi clicado
  if (req.indexOf("ioonred") != -1){
    M5.dis.fillpix(CRGB(0xFF0000));
    myStatusOUT1 = HIGH;
  }
  else if (req.indexOf("ioonBlue") != -1){
     M5.dis.fillpix(CRGB(0x0000FF));
    myStatusOUT1 = HIGH;
  }
  else if (req.indexOf("ioonGreen") != -1){
    M5.dis.fillpix(CRGB(0x00FF00));
    myStatusOUT1 = HIGH;
  }

  else if (req.indexOf("iooff") != -1){
    M5.dis.fillpix(CRGB(0x000000));
    myStatusOUT1 = LOW;
  }

  // HTML 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Cor Desejada</h1>");

  if(!myStatusOUT1){
    client.println("<p>RED <a href=\"ioonred\"><button>LIGAR</button></a></p>");
    client.println("<p>BLUE <a href=\"ioonBlue\"><button>LIGAR</button></a></p>");
    client.println("<p>GREEN <a href=\"ioonGreen\"><button>LIGAR</button></a></p>");
  }

  else
    client.println("<p><a href=\"iooff\"><button>DESLIGAR</button></a></p>");

  client.println("</html>");
  delay(10);
}
