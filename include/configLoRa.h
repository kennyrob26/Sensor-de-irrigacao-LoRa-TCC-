#ifndef __CONFIG_LORA__
    #define __CONFIG_LORA__

    #include "DEBUG.h"

    #include <SPI.h>
    #include <LoRa_STM32.h>
    #include "serializacaoBinaria.h"

    void iniciarLoRa();
    void desligarLoRa();
    void enviarMensagem(uint8_t identificador, int8_t umidade_solo, float temperatura_ambiente, int8_t umidade_ambiente, float tensao_placa);
#endif