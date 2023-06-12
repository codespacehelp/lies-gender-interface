#include <WiFi.h>
#include <PubSubClient.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

const char* ssid = "dlink-3MR6";
const char* password = "royalcheese820";

const char* mqttServer = "discodonkey315.cloud.shiftr.io";
const int mqttPort = 1883;
const char* mqttUser = "discodonkey315";
const char* mqttPassword = "J7Z5SMjyxjahZhhP";


void onMessage(const char* topic, byte* payload, unsigned int length);

WiFiClient espClient;
PubSubClient client(espClient);

int GPIOS0 = 15;
int GPIOS1 = 2;
int GPIOS2 = 0;
int GPIOS3 = 4;

int GPIOSIG1 = 16;
int GPIOSIG2 = 17;
int GPIOSIG3 = 5;
int GPIOSIG4 = 18;
int GPIOSIG5 = 19;
int GPIOSIG6 = 22;
int GPIOSIG7 = 23;

int GPIOEN = 13;

int male_Boys_6_OnlyMen = 0;
int male_Girls_6_OnlyMen = 0;
int male_Boys_6_MostlyMen = 0;
int male_Girls_6_MostlyMen = 0;
int male_Boys_6_Both = 0;
int male_Girls_6_Both = 0;
int male_Girls_6_MostlyWoman = 0;
int male_Boys_6_OnlyWoman = 0;

int male_Boys_7_OnlyMen = 0;
int male_Girls_7_OnlyMen = 0;
int male_Boys_7_MostlyMen = 0;
int male_Girls_7_MostlyMen = 0;
int male_Boys_7_Both = 0;
int male_Girls_7_Both = 0;
int male_Girls_7_OnlyWoman = 0;

int male_Boys_8_OnlyMen = 0;
int male_Girls_8_OnlyMen = 0;
int male_Boys_8_MostlyMen = 0;
int male_Girls_8_MostlyMen = 0;
int male_Boys_8_Both = 0;
int male_Girls_8_Both = 0;
int male_BoysGirls_8_MostlyWoman = 0;
int male_Boys_8_OnlyWoman = 0;

int male_Boys_9_OnlyMen = 0;
int male_Girls_9_OnlyMen = 0;
int male_Boys_9_MostlyMen = 0;
int male_Girls_9_MostlyMen = 0;
int male_Boys_9_Both = 0;
int male_Girls_9_Both = 0;

int male_Boys_10_OnlyMen = 0;
int male_Girls_10_OnlyMen = 0;
int male_Boys_10_MostlyMen = 0;
int male_Girls_10_MostlyMen = 0;
int male_Boys_10_Both = 0;
int male_Girls_10_Both = 0;
int male_BoysGirls_10_MostlyWoman = 0;

int male_Boys_11_OnlyMen = 0;
int male_Girls_11_OnlyMen = 0;
int male_Boys_11_MostlyMen = 0;
int male_Girls_11_MostlyMen = 0;
int male_Boys_11_Both = 0;
int male_Girls_11_Both = 0;
int male_BoysGirls_11_MostlyWoman = 0;
int male_Boys_11_OnlyWoman = 0;

int male_Boys_12_OnlyMen = 0;
int male_Girls_12_OnlyMen = 0;
int male_Boys_12_MostlyMen = 0;
int male_Girls_12_MostlyMen = 0;
int male_Boys_12_Both = 0;
int male_Girls_12_Both = 0;

int both_Boys_6_OnlyMen = 0;
int both_Girls_6_OnlyMen = 0;
int both_Boys_6_MostlyMen = 0;
int both_Girls_6_MostlyMen = 0;
int both_Boys_6_Both = 0;
int both_Girls_6_Both = 0;
int both_BoysGirls_6_MostlyWoman = 0;
int both_BoysGirls_6_OnlyWoman = 0;

int both_Boys_7_OnlyMen = 0;
int both_Girls_7_OnlyMen = 0;
int both_Boys_7_MostlyMen = 0;
int both_Girls_7_MostlyMen = 0;
int both_Boys_7_Both = 0;
int both_Girls_7_Both = 0;
int both_BoysGirls_7_MostlyWoman = 0;
int both_BoysGirls_7_OnlyWoman = 0;

int both_Boys_8_OnlyMen = 0;
int both_Girls_8_OnlyMen = 0;
int both_Boys_8_MostlyMen = 0;
int both_Girls_8_MostlyMen = 0;
int both_Boys_8_Both = 0;
int both_Girls_8_Both = 0;
int both_BoysGirls_8_MostlyWoman = 0;
int both_Girls_8_OnlyWoman = 0;

int both_Boys_9_OnlyMen = 0;
int both_Girls_9_OnlyMen = 0;
int both_Boys_9_MostlyMen = 0;
int both_Girls_9_MostlyMen = 0;
int both_Boys_9_Both = 0;
int both_Girls_9_Both = 0;

int both_Boys_10_OnlyMen = 0;
int both_Girls_10_OnlyMen = 0;
int both_Boys_10_MostlyMen = 0;
int both_Girls_10_MostlyMen = 0;
int both_Boys_10_Both = 0;
int both_Girls_10_Both = 0;
int both_Boys_10_MostlyWoman = 0;
int both_Boys_10_OnlyWoman = 0;

int both_Boys_11_OnlyMen = 0;
int both_Girls_11_OnlyMen = 0;
int both_Boys_11_MostlyMen = 0;
int both_Girls_11_MostlyMen = 0;
int both_Boys_11_Both = 0;
int both_Girls_11_Both = 0;

int both_Boys_12_OnlyMen = 0;
int both_Girls_12_OnlyMen = 0;
int both_Boys_12_MostlyMen = 0;
int both_Girls_12_MostlyMen = 0;
int both_Boys_12_Both = 0;
int both_Girls_12_Both = 0;

// 74HC4067 multiplexer demonstration (16 to 1)

// control pins output table in array form
// see truth table on page 2 of TI 74HC4067 data sheet
// connect 74HC4067 S0~S3 to Arduino D7~D4 respectively
// connect 74HC4067 pin 1 to Arduino A0
byte controlPins[] = {B00000000, 
                  B10000000,
                  B01000000,
                  B11000000,
                  B00100000,
                  B10100000,
                  B01100000,
                  B11100000,
                  B00010000,
                  B10010000,
                  B01010000,
                  B11010000,
                  B00110000,
                  B10110000,
                  B01110000,
                  B11110000 }; 

// holds incoming values from 74HC4067                  
byte muxValues[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
enum Option1 {Men, Both};
 

void setup() {

  pinMode(GPIOS0, OUTPUT);
  pinMode(GPIOS1, OUTPUT);
  pinMode(GPIOS2, OUTPUT);
  pinMode(GPIOS3, OUTPUT);
 
  pinMode(GPIOSIG1, OUTPUT);
  pinMode(GPIOSIG2, OUTPUT);
  pinMode(GPIOSIG3, OUTPUT);
  pinMode(GPIOSIG4, OUTPUT);
  pinMode(GPIOSIG5, OUTPUT);
  pinMode(GPIOSIG6, OUTPUT);
  pinMode(GPIOSIG7, OUTPUT);

  Serial.begin(115200); 

    WiFi.begin(ssid, password);

  Serial.println("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to Wi-Fi. IP = ");
  Serial.println(WiFi.localIP());

  client.setServer(mqttServer, mqttPort);
  client.setCallback(onMessage);


}

void loop() {

     if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "esp32";
    if (client.connect(clientId.c_str(), mqttUser, mqttPassword)) {
      Serial.println(" OK!");
      client.publish("chat", "esp32_connected");
      client.subscribe("steer");

      digitalWrite(forwardPin, HIGH);
      delay(200);
      digitalWrite(forwardPin, LOW);
      delay(200);
      digitalWrite(forwardPin, HIGH);
      delay(200);
      digitalWrite(forwardPin, LOW);
      delay(200);

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}



void onMessage(const char* topic, byte* payload, unsigned int length) {

  digitalWrite(GPIOEN, HIGH);
  digitalWrite(GPIOS0, HIGH);
 
//  while (Serial.available() > 0) {
//     delay(100);
//   }
 
//   Serial.println("Give Option : (e.g. mb6o)");
//   String input = Serial.readString();

  char* message = (char*) payload;

  switch (tolower(message[0])) {
    case 'm':
      
      switch (tolower(message[1])) {
        case 'b':
          
          switch (tolower(message[2])) {
            case '6':
              
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;        
              }
              break;
            case '7':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '8':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '9':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '10':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '11':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '12':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;            
          }
          break;
        case 'g':
          switch (tolower(message[2])) {
            case '6':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;        
              }
              break;
            case '7':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '8':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '9':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '10':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '11':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '12':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, HIGH);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, HIGH);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, HIGH);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;            
          }
          break;
        case 'r':
          digitalWrite(GPIOS0, LOW);
          break;    
      }  
     
      break;
    case 'b': 
      switch (tolower(message[1])) {
        case 'b':
          switch (tolower(message[2])) {
            case '6':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;        
              }
              break;
            case '7':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '8':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '9':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '10': 
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '11':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '12':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;            
          }
          break;
        case 'g':
          switch (tolower(message[2])) {
            case '6':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;        
              }
              break;
            case '7':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '8':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '9':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '10':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '11':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;
            case '12':
              switch (tolower(message[3])) {
                case 'o':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, HIGH);
                  break;
                case 'm':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, HIGH);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, HIGH);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'b':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, HIGH);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, HIGH);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'w':
                  digitalWrite(GPIOS0, LOW);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, LOW);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, LOW);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
                case 'f':
                  digitalWrite(GPIOS0, HIGH);
                  digitalWrite(GPIOS1, LOW);
                  digitalWrite(GPIOS2, HIGH);
                  digitalWrite(GPIOS3, LOW);
                  
                  digitalWrite(GPIOSIG1, LOW);
                  digitalWrite(GPIOSIG2, LOW);
                  digitalWrite(GPIOSIG3, LOW);
                  digitalWrite(GPIOSIG4, HIGH);
                  digitalWrite(GPIOSIG5, LOW);
                  digitalWrite(GPIOSIG6, LOW);
                  digitalWrite(GPIOSIG7, LOW);
                  break;
              }
              break;            
          }
          break;
        case 'r':
          digitalWrite(GPIOS0, LOW);
          break;    
      }  
      
      break;
    case 'r':
      digitalWrite(GPIOSIG7, LOW);
      digitalWrite(GPIOSIG1, LOW);
      digitalWrite(GPIOSIG2, LOW);
      digitalWrite(GPIOSIG3, LOW);
      digitalWrite(GPIOSIG4, LOW);
      digitalWrite(GPIOSIG5, LOW);
      digitalWrite(GPIOSIG6, LOW);
      
      break;  
  }
}


/*
void SetON(int EN, int S0, int S1, int S2, int S3, int S4) {
  digitalWrite(GPIOEN, HIGH);
  digitalWrite(GPIOS0, S0);
  digitalWrite(GPIOS1, S1);
  digitalWrite(GPIOS2, S2);
  digitalWrite(GPIOS3, S3);
  digitalWrite(GPIOS4, S4);

}
*/

