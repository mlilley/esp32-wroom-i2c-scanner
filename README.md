ESP32-WROOM-32 pinout
```
                       +------------+
           VIN 3.3V 19 |            | 38 GND
           RESET EN 18 | +--------+ | 37 GPIO23 
        ADC0 GPIO36 17 | |        | | 36 GPIO22 I2CSCL
        ADC3 GPIO39 16 | |        | | 35 GPIO1  TX0
        ADC6 GPIO34 15 | |        | | 34 GPIO3  RX0
        ADC7 GPIO35 14 | +--------+ | 33 GPIO21 I2CSDA
 TOUCH9 ADC4 GPIO32 13 |            | 32 GND
 TOUCH8 ADC5 GPIO33 12 |            | 31 GPIO19 VSPI MISO
       ADC18 GPIO25 11 |            | 30 GPIO18 VSPI SCK
       ADC19 GPIO26 10 |            | 29 GPIO5  VSPI SS
TOUCH7 ADC17 GPIO27  9 |    TOP     | 28 GPIO17
TOUCH6 ADC16 GPIO14  8 |            | 27 GPIO16
TOUCH5 ADC15 GPIO12  7 |            | 26 GPIO4 ADC10 TOUCH0
                GND  6 |            | 25 GPIO0 ADC11 TOUCH1
TOUCH4 ADC14 GPIO13  5 |            | 24 GPIO2 ADC12 TOUCH2
     FLASH D2 GPIO9  4 |            | 23 GPIO15 ADC13 TOUCH3
    FLASH D3 GPIO10  3 |            | 22 GPIO8 FLASH D1
   FLASH CMD GPIO11  2 |            | 21 GPIO7 FLASH D0
             VIN 5V  1 | o +----+ o | 20 GPIO6 FLASH SCK
                       +---|    |---+ 
                           +----+
```

I2C uses 2 pins; SDA and SCL. These default to GPIO21 (pin 33) and GPIO22 (pin 36), but any GPIO pins can be used if configured explicitly.

Call Wire.begin() (to use the default pins), or Wire.begin(SDA_PIN, SCL_PIN) to use others.

By default the PlatformIO serial monitor runs at 9600 baud, and this needs to be configured in code using Serial.begin(9600).
Setting the monitor to a different baud, and/or configuring a different baud in code, for this mcu, doesn't seem to work.
