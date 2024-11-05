#include "configAht10.h"

#define SDA_DEFAULT PB7
#define SCL_DEFAULT PB6

Adafruit_AHTX0 aht;

sensors_event_t humidity, temp;

void iniciarAHT()
{
    iniciarAHT(SDA_DEFAULT, SCL_DEFAULT);
}
void iniciarAHT(uint8_t sda_pin, uint8_t scl_pin)
{
    Wire.begin(sda_pin, scl_pin);
    if(!aht.begin())
    {
        DEBUG_PRINTLN("configAHT10 - ERRO: O sensor não foi encontrado!!!");
    }
    DEBUG_PRINTLN("configAht10 - Sensor Iniciado com sucesso!!!");

    if(!aht.getEvent(&humidity, &temp))
    {
        DEBUG_PRINTLN("configAHT - Falha na Leitura");
        return;
    }

    Wire.end();

    //Pinos I2C
    pinMode(PB6, INPUT_ANALOG);
    pinMode(PB7, INPUT_ANALOG);
    
}

/*
void desligarSensor()
{
    Wire.end();

    //Pinos I2C
    pinMode(PB6, INPUT_ANALOG);
    pinMode(PB7, INPUT_ANALOG);
}
void novaLeituraAHT()
{
    if(!aht.getEvent(&humidity, &temp))
    {
        DEBUG_PRINTLN("configAHT - Falha na Leitura");
        return;
    }
}
*/
float getTemperaturaAmbiente()
{
    //Considera apenas a primeira casa decimal (precisão do sensor)
    float temperatura_ambiente = (int)(temp.temperature * 10);
    temperatura_ambiente = temperatura_ambiente / 10.0;
    
    return temperatura_ambiente;
}
uint8_t getUmidadeAmbiente()
{
    uint8_t umidade_ambiente = round(humidity.relative_humidity);
    return umidade_ambiente;
}

