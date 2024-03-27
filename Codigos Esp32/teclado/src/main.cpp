
#include <Arduino.h>
#include "I2CKeyPad.h"
#include "Wire.h"

const char keys[] = "123A456B789C*0#DNF"; // N = NoKey, F = Fail
// endereco padrao PCF8574
const uint8_t KEYPAD_ADDRESS = 0x20;

I2CKeyPad keyPad(KEYPAD_ADDRESS);

uint32_t start, stop;
volatile bool keyPressed = false;
byte lastKeyPressed = 'N';
void sendFlag();
#define SDA_PIN 22
#define SCL_PIN 23

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(34, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(34), sendFlag, FALLING);

  Wire.begin(SDA_PIN, SCL_PIN);
  if (keyPad.begin() == false)
  {
    Serial.println("\nERROR: cannot communicate to keypad.\nPlease reboot.\n");
    while (1)
      ;
  }
}

void loop()
{
  if (keyPressed == true)
  {

    uint8_t index = keyPad.getKey();

    if (index < 16 && lastKeyPressed != index)
    {

      Serial.println(keys[index]);
    }
    lastKeyPressed = index;
    keyPressed = false;
  }
}

void IRAM_ATTR sendFlag()
{
  keyPressed = true;
}
