#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Definindo os pinos SDA e SCL
#define SDA_PIN 22
#define SCL_PIN 23

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Inicializando a comunicação I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Inicializando o display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao inicializar o display OLED"));
    for (;;);
  }

  // Limpando o buffer do display
  display.clearDisplay();

  // Desenhando alguns textos
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello, ESP32!");
  display.println("OLED Teste");
  display.println("SOCORRO DEUS");

  // Exibindo os textos no display
  display.display();
}

void loop() {
  // Não há nada a ser feito no loop neste exemplo
}