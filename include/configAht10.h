#ifndef __CONFIG_AHT10__
    #define __CONFIG_AHT10__

    #include "DEBUG.h"

    #include <Arduino.h>
    #include <Wire.h>
    #include <Adafruit_AHTX0.h>

    void iniciarAHT();
    void iniciarAHT(uint8_t sda_pin, uint8_t scl_pin);
    //void novaLeituraAHT();
    //void desligarSensor();
    float getTemperaturaAmbiente();
    uint8_t getUmidadeAmbiente();
#endif