#include <Arduino.h>
#include <Wire.h>

// (the defaults)
#define SDA_GPIO_PIN 21
#define SCL_GPIO_PIN 22

void setup() {
    Serial.begin(9600);
    Serial.println("Running!");

    Wire.begin(SDA_GPIO_PIN, SCL_GPIO_PIN);
    Serial.printf("Using I2C Configuration: SDA=GPIO%d, SCL=GPIO%d\n", SDA_GPIO_PIN, SCL_GPIO_PIN);

    delay(2000);    
}

void loop() {
    int nDevices = 0;

    Serial.println("Scanning...");

    byte err, addr;
    for (addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        err = Wire.endTransmission();
        
        switch (err) {
            case 0:
                Serial.printf("Address 0x%x: device found!\n", addr);
                nDevices++;
                break;
            case 1:
                Serial.printf("Address 0x%x: error (data too long)\n", addr);
                break;
            case 2:
                // normal response (nack on address tx) for no device at this address
                break;
            case 3:
                Serial.printf("Address 0x%x: error (nack on data tx)\n", addr);
                break;
            case 4:
                Serial.printf("Address 0x%x: error (unknown)\n", addr);
                break;
            case 5:
                Serial.printf("Address 0x%x: timeout\n", addr);
                break;
            default:
                Serial.printf("Address 0x%x: unrecognized api return value: %hhx\n", addr, err);
        }
    }

    Serial.printf("Done (%d devices found)\n", nDevices);
    delay(5000);
}
