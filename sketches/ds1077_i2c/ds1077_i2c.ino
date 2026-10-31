/*
 * ds1077_i2c - I2C bring-up for the Dallas/Maxim DS1077 EconOscillator.
 *
 * TARGET: Arduino Micro (ATmega32U4, 5 V logic). SCL = D2, SDA = D3.
 *
 * STATUS: untested. Read NOTES.md before wiring anything.
 * This is a measurement tool, not a finished driver: it scans the bus,
 * writes a divider, reads it back, and dumps registers so a scope reading
 * and the serial log can be compared.
 */

#include <Wire.h>

// 7-bit address = 1011 (hardwired) + 3 strap bits. Range 0x58..0x5F.
// Set to match YOUR strap pins. The bus scan will tell you the truth.
const uint8_t DS1077_ADDR = 0x58;

// Register select bytes. VERIFY against the datasheet register map before
// trusting a write - these are the one thing not confirmed from a primary
// source in this session.
const uint8_t REG_MUX = 0x01;
const uint8_t REG_DIV = 0x02;

// Internal store takes ~10 ms. Do not hammer it in a loop.
const uint16_t STORE_MS = 20;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 3000) {}
  Wire.begin();
  Serial.println(F("DS1077 I2C bring-up"));
  scanBus();
}

void loop() {
  setDivider(2);
  dumpRegisters();
  delay(5000);
}

void scanBus() {
  Serial.println(F("Scanning I2C bus..."));
  uint8_t found = 0;
  for (uint8_t a = 0x08; a < 0x78; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0) {
      Serial.print(F("  device at 0x"));
      if (a < 0x10) Serial.print('0');
      Serial.println(a, HEX);
      found++;
    }
  }
  if (!found) {
    Serial.println(F("  nothing found - check SDA/SCL, pullups, power"));
    Serial.println(F("  DS1077 should appear between 0x58 and 0x5F"));
  }
}

bool readReg(uint8_t reg, uint8_t &value) {
  Wire.beginTransmission(DS1077_ADDR);
  Wire.write(reg);
  if (Wire.endTransmission(false) != 0) return false;
  if (Wire.requestFrom(DS1077_ADDR, (uint8_t)1) != 1) return false;
  value = Wire.read();
  return true;
}

void dumpRegisters() {
  uint8_t mux = 0, msb = 0, lsb = 0;
  if (readReg(REG_MUX, mux)) {
    Serial.print(F("MUX = 0b")); printBin8(mux); Serial.println();
  } else {
    Serial.println(F("MUX read FAILED - check address and wiring"));
  }
  if (readReg(REG_DIV, msb) && readReg(REG_DIV + 1, lsb)) {
    Serial.print(F("DIV MSB = 0b")); printBin8(msb);
    Serial.print(F("  LSB = 0b")); printBin8(lsb);
    Serial.println();
  } else {
    Serial.println(F("DIV read FAILED"));
  }
}

bool setDivider(uint16_t n) {
  uint8_t msb = (n >> 2) & 0xFF;
  uint8_t lsb = n & 0x03;
  Serial.print(F("Setting divider N = ")); Serial.print(n);
  Wire.beginTransmission(DS1077_ADDR);
  Wire.write(REG_DIV);
  Wire.write(msb);
  Wire.write(lsb);
  uint8_t err = Wire.endTransmission();
  if (err) { Serial.print(F(" -> write NAK, err ")); Serial.println(err); return false; }
  delay(STORE_MS);
  uint8_t rbM = 0, rbL = 0;
  if (!readReg(REG_DIV, rbM) || !readReg(REG_DIV + 1, rbL)) {
    Serial.println(F(" -> readback failed"));
    return false;
  }
  uint16_t rb = ((uint16_t)rbM << 2) | (rbL & 0x03);
  Serial.print(F(" -> readback ")); Serial.println(rb);
  return rb == n;
}

void printBin8(uint8_t v) {
  for (int8_t i = 7; i >= 0; i--) Serial.print((v >> i) & 1);
}
