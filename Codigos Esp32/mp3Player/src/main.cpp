#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
//static const uint8_t PIN_MP3_TX = 26; // Connects to module's RX 
//static const uint8_t PIN_MP3_RX = 27; // Connects to module's TX 

// Hardware Serial 2 pins
#define RXD2 32
#define TXD2 33

// SoftwareSerial softwareSerial = new SoftwareSerial(PIN_MP3_RX, PIN_MP3_TX);
// Create the Player object
DFRobotDFPlayerMini player;

void setup() {

  // Init USB serial port for debugging
  Serial1.begin(9600);
  Serial.begin(115200);
  // Init serial port for DFPlayer Mini
  //softwareSerial.begin(9600);

  delay(1000);
  // Start communication with DFPlayer Mini
  if (!player.begin(Serial1)) {
   Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(1);
    // Play the first MP3 file on the SD card
    player.play(1);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

void loop() {

 
   }


// #include <Arduino.h>
// #include "DFRobotDFPlayerMini.h"

// // Define os pinos RX e TX para a comunicação serial 2
// #define RXD2 32
// #define TXD2 33

// // Cria o objeto Player
// DFRobotDFPlayerMini player;

// void setup() {
//   // Inicializa a comunicação serial 1 para debug
//   Serial.begin(115200);
  
//   // Inicializa a comunicação serial 2 para o DFPlayer Mini
//   Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

//   delay(1000);

//   // Inicia a comunicação com o DFPlayer Mini
//   if (!player.begin(Serial2)) {
//     Serial.println("Conexão com o DFPlayer Mini estabelecida com sucesso!");
//     // Define o volume para o máximo (0 a 30)
//     player.volume(5);
//     // Reproduz o primeiro arquivo MP3 no cartão SD
//     player.play(1);
//   } else {
//     Serial.println("Falha ao conectar ao DFPlayer Mini!");
//   }
// }

// void loop() {
//   // O loop está vazio, você pode adicionar seu código aqui se necessário
// }
