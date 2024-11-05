#include "configLoRa.h"

#define SS PB12
#define RST PA8
#define DI0 PA15
 
#define TX_P          20                //20dBM
#define BAND       915E6                //915MHz  
#define BAND_WIDTH 125E3                //125MHz
//#define SF         10
#define SF         12
#define CR         4                    // CR 5/4
//#define ENCRYPT    0xA5                 //Chave de Sincronismo

void iniciarLoRa()
{
while (!Serial);
 
  DEBUG_PRINTLN("configLoRa - Iniciando o Módulo");
 
  LoRa.setTxPower(TX_P);
  //LoRa.setSyncWord(ENCRYPT);
  LoRa.setSignalBandwidth(BAND_WIDTH);
  LoRa.setSpreadingFactor(SF);
  LoRa.setCodingRate4(CR);
  
  LoRa.setPins(SS, RST, DI0);
  if (!LoRa.begin(BAND)) 
  {
    DEBUG_PRINTLN("configLoRa - ERRO! Módulo não pode ser iniciado!");
    while (1);
  }
}

void desligarLoRa()
{
  LoRa.end();

  digitalWrite(PB13, LOW);    //SCK
  pinMode(PB13, OUTPUT);

  pinMode(PB14, INPUT_ANALOG);

  digitalWrite(PB15, LOW);   //MOSI
  pinMode(PB15, OUTPUT);

  digitalWrite(SS, LOW); 
  pinMode(SS, OUTPUT);

  pinMode(DI0, INPUT_ANALOG); // IO 0

  pinMode(RST, INPUT_ANALOG);   //RST
}


void enviarMensagem(uint8_t identificador, int8_t umidade_solo, float temperatura_ambiente, int8_t umidade_ambiente, float tensao_placa)
{
  uint8_t bytes[6];

  serializar(identificador, umidade_solo, temperatura_ambiente, umidade_ambiente, tensao_placa, bytes);

  LoRa.beginPacket();
  LoRa.write(bytes, sizeof(bytes));

  LoRa.endPacket();  

  desligarLoRa();
}