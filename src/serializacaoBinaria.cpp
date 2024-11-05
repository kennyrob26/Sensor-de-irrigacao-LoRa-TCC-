#include "serializacaoBinaria.h"

// 0 -> Sensor / 1 -> Atuador
#define TIPO_NO 0

void serializar(uint8_t identificador, int8_t umidade_solo, float temp_ambiente, int8_t umidade_ambiente, float tensao_placa, uint8_t* buffer)
{
    //Salva o tipo de nó no primeiro bit e o identificador nos 7 bits restantes
    uint8_t id = (TIPO_NO << 7) | (identificador & 0x7F);

    //Converte float para uma representação inteira. Ex 25.3 * 10 = 253
    uint16_t t_ambiente  = temp_ambiente * 100;
    uint8_t tensaoPlaca  = tensao_placa  * 100;

    buffer[0] = id & 0xFF;                        //Byte 1

    buffer[1] = (t_ambiente >> 8) & 0xFF;
    buffer[2] = t_ambiente & 0xFF;                //Bytes 2 e 3

    buffer[3] = umidade_solo & 0xFF;              //Byte 4
    buffer[4] = umidade_ambiente & 0xFF;          //Byte 5
    buffer[5] = tensaoPlaca & 0xFF;               //Byte 6
}


void desserializar(const uint8_t* buffer, float& umidade_solo, float& temp_ambiente, float& umidade_ambiente, float& tensaoPlaca)
{
    //Dividimos por 10 para voltar o inteiro para float Ex: 253/10 = 25.3 
    umidade_solo     = ((buffer[0] << 8) | buffer[1]);
    temp_ambiente    = ((buffer[2] << 8) | buffer[3]) / 100.0;
    umidade_ambiente = ((buffer[4] << 8) | buffer[5]);
    tensaoPlaca      = ((buffer[6] << 8) | buffer[7]) / 100.0;
}