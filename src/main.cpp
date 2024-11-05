
#include "main.h"

#define TEMPO_SONO 120000


/*==================== --- SETUP --- =====================*/

void desativarPinosInativos();
void sleep();

void setup() 
{
  iniciarSensorSolo();
  DEBUG_SERIAL_BEGIN(115200);
  desativarPinosInativos();
  iniciarLoRa();
  //desligarLoRa();
  
  iniciarAHT();
  
 

  DEBUG_PRINT("Temperatura: ");
  DEBUG_PRINTLN(getTemperaturaAmbiente());
  DEBUG_PRINT("Umidade Ar: ");
  DEBUG_PRINTLN(getUmidadeAmbiente());
  DEBUG_PRINT("Umidade Solo:");
  DEBUG_PRINTLN(getUmidadeSolo());


  enviarMensagem(1, getUmidadeSolo(), getTemperaturaAmbiente(), getUmidadeAmbiente(), 0);
  /*
  delay(100);
  enviarMensagem(2, getUmidadeSolo(), getTemperaturaAmbiente(), getUmidadeAmbiente(), 5.7);
  delay(100);
  enviarMensagem(3, getUmidadeSolo(), getTemperaturaAmbiente(), getUmidadeAmbiente(), 5.7);
  delay(100);
  enviarMensagem(4, getUmidadeSolo(), getTemperaturaAmbiente(), getUmidadeAmbiente(), 5.7);
  delay(100);
  enviarMensagem(5, getUmidadeSolo(), getTemperaturaAmbiente(), getUmidadeAmbiente(), 5.7);
  delay(100);
  enviarMensagem(6, getUmidadeSolo(), getTemperaturaAmbiente(), getUmidadeAmbiente(), 5.7);
  delay(100);
  */
  sleep();
  
}
 
void loop() 
{

}

void desativarPinosInativos()
{
// Pinos não tolerantes a 5V (colocar em INPUT_ANALOG)
  pinMode(PA3, INPUT_ANALOG);   //Tensão placa
  pinMode(PA4, INPUT_ANALOG);
  pinMode(PA5, INPUT_ANALOG);
  pinMode(PA6, INPUT_ANALOG);
  pinMode(PA7, INPUT_ANALOG);



  pinMode(PA11, INPUT_ANALOG);
  pinMode(PA12, INPUT_ANALOG);
  pinMode(PA15, INPUT_ANALOG);
  pinMode(PB0, INPUT_ANALOG);
  pinMode(PB1, INPUT_ANALOG);
  pinMode(PB3, INPUT_ANALOG);
  pinMode(PB4, INPUT_ANALOG);
  pinMode(PB8, INPUT_ANALOG);
  pinMode(PB9, INPUT_ANALOG);
  pinMode(PB10, INPUT_ANALOG);
  pinMode(PB11, INPUT_ANALOG);
  pinMode(PC13, INPUT_ANALOG);
  pinMode(PC14, INPUT_ANALOG);
  pinMode(PC15, INPUT_ANALOG);


}

void sleep()
{
  LowPower.begin();

  DEBUG_SERIAL_END();

  //Desativa os pinos do serial
  pinMode(PA9, INPUT_ANALOG);
  pinMode(PA10, INPUT_ANALOG);
  
  LowPower.shutdown(TEMPO_SONO);
}