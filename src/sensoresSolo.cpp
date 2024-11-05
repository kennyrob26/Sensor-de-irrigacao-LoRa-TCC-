#include "sensoresSolo.h"

#define SENSOR1 PA0
#define SENSOR2 PA1
#define SENSOR3 PA2

#define TRANSISTOR PB5

#define VALOR_MIN 70
#define VALOR_MAX 4000


#define NUM_AMOSTRAS 50
void iniciarSensorSolo()
{
    pinMode(SENSOR1, INPUT_ANALOG);
    pinMode(SENSOR2, INPUT_ANALOG);
    pinMode(SENSOR3, INPUT_ANALOG);
    pinMode(TRANSISTOR, OUTPUT);

    digitalWrite(TRANSISTOR, HIGH);

    analogReadResolution(12);
}
int8_t getUmidadeSolo()
{
    //Quantidade de sensores com leitura válida
    uint8_t sensores_ativos = 3;

    float sensor[3];

    sensor[0] = lerSensor(SENSOR1);
    sensor[1] = lerSensor(SENSOR2);
    sensor[2] = lerSensor(SENSOR3);
          
    float soma = 0;
    //Verifica se o valor de cada sensor é valido e soma
    for(uint8_t i = 0; i<3; i++)
    {
        //Serial.printf("Leitura[%d] =", i);
        //Serial.println(sensor[i]);
        
        if(sensor[i] == -1)
        {
            sensor[i] = 0;              // 0 é neutro na soma
            sensores_ativos -= 1;       //subtrai 1 dos sensores ativos
        }
        soma += sensor[i];
        
    }

    int8_t media_umidade = -1;
    
    if(sensores_ativos > 0)
        media_umidade = round(soma / sensores_ativos);
    

    //Corta a alimentação dos sensores
    digitalWrite(TRANSISTOR, LOW);

    return media_umidade;

}

float lerSensor(uint8_t sensor)
{
    uint32_t amostras = 0;

    for(uint8_t i = 0; i < NUM_AMOSTRAS; i++)
        amostras += analogRead(sensor);

    amostras = (int) amostras / NUM_AMOSTRAS;
    DEBUG_PRINTLN("Sensor_Serial: ");
    DEBUG_PRINTLN(amostras);
    //Faixa de valores inválidas
    if (amostras < VALOR_MIN || amostras > VALOR_MAX)
        return(-1);

    
    
    float leitura = (map(amostras, 90, 3500, 0, 1000)) / 10.0;

    if(leitura > 100) 
        leitura = 100;

    return leitura;

    
}