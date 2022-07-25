#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
};
IPAddress ip(192, 168, 0, 26);
IPAddress myDns(1, 1, 1, 1);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);


EthernetServer server(23); // telnet port 23
bool gotAMessage = false; // whether or not you got a message from the client yet
string TOKEN = "01";
void setup() {
  Ethernet.init(10);
  Serial.begin(9600);

  while (!Serial) {;}
  Serial.println("Trying to get an IP address using DHCP");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1);
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    Ethernet.begin(mac, ip, myDns, gateway, subnet);
  }

  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  server.begin();
}


void loop() {
  EthernetClient client = server.available();

  if (client) {
    if (!gotAMessage) {
      Serial.println("We have a new client");
      client.println("Hello, client!");
      gotAMessage = true;
    }
    char thisChar = client.read();
    server.write(thisChar);
    Serial.print(thisChar);
    Serial1.print(thisChar);
    Ethernet.maintain();
  }
}
