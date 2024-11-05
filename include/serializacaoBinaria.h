#ifndef __SERIALIALIZACAO_BINARIA__
    #define __SERIALIALIZACAO_BINARIA__
    
    #include "DEBUG.h"
    
    #include <stdint.h>

    //Transforma os valores inteiros em uma sequencia de bytes
    void serializar(uint8_t identificador, int8_t umidade_solo, float temp_ambiente, int8_t umidade_ambiente, float tensao_placa, uint8_t* buffer);

    //transforma a sequencia de bytes em inteiros novamente
    void desserializar(const uint8_t* buffer, float umidade_solo, float temp_ambiente, float umidade_ambiente, float tensaoPlaca);

#endif