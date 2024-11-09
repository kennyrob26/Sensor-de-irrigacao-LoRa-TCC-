# Sensor-de-irrigacao-LoRa-TCC
Este projeto foi desenvolvido no segundo semestre de 2024, para o **TCC do curso de Engenharia da Computação da UNIVESP**. O projeto consiste em um sensor que permite a coleta da umidade do solo utilizando a média de 3 sensores, além de permitir coletar os dados do ambiente, como a temperatura e a umidade. O projeto foi desenvolvido utilizando o PlatformIO em conjunto com o Arduino Framework. O microcontrolador utilizado é o STM32, e o RFM95 é o responsável pela comunicação LoRa. Para a coleta da umidade do solo optamos pela utilzação de sensores resistivos, e para coletar os dados do ambiente o sensor AHT10 foi escolhido.  
A solução desenvolvida é muito eficiente, com um consumo de **27µA** em modo sono, o que nos permite uma autonomia de até 4 anos utilizando uma bateria de 3000mAh enviando dados a cada 2 minutos.

## Visão Geral da Solução
Para melhor entendimento da solução vamos separar em 3 partes, o sensor que envia dados, o gateway que recebe e repassa os dados para o servidor, e o servidor por sua vez toma decisões sobre os dados, veja em mais detalhes:
* **Sensor**
    * O sensor é todo o **Hardware** desenvolvido, na versão atual o sensor **apenas envia dados**, ou seja pertence a classe A, que são dispositivos que passam a maior parte do tempo desligados, e só são acionados quando é necessário enviar dados, visando o consumo mínimo.
*  **Gateway**
    * Neste projeto o nosso gateway é um **ESP32 S3 em conjunto com um RFM95**, este é responsável por receber os dados enviados via LoRaWan pelo sensor, a topologia utilizada entre os sensore e o gateway é a topologia em estrela.
    * A comunicação entre o Gateway e o servidor utiliza o protocolo MQTT, ou seja, o gateway recebe os dados via LoRaWan e repassa para o servidor via MQTT.
*  **Servidor**
    * O servidor é quem recebe os dados MQTT repassado pelo Gateway. Na versão atual o sensor está hospedado em um *droplet* da Digital Ocean, utiliza como SO o Debian, o broker MQTT utilizado é o Mosquitto e todo o backend é responsábilidade do node-red.
    * O Servidor disponibiliza toda a parte visual do projeto, como os dados e **gráficos**, além de **APIs**, com o histórico de cada sensor.

## A plataforma desenvolvida
Para conseguirmos visualizar o funcionamento do sensor nós decidimos desenvolver uma pequena [plataforma](https://plataformaiot.com.br/dashboard/Sensores), onde **cada sensor é representado por um simbolo no mapa**, de acordo com a sua localização. O usuário pode interagir com o mapa e visualizar os dados de cada sensor clicando sobre eles. Também é possível gerar **gráficos** sobre o histórico de cada sensor, além da possibilidade de **filtrar por data e hora**. A plataforma foi desenvolvida utilizando o projeto [Dashsboard 2.0](https://dashboard.flowfuse.com/), ou seja, a página é um PWA, permitindo grande acessibilidade em todos os dispositivos, e pode até mesmo rodar como um aplicativo nativo.  
[Plataforma - Sensores no mapa](Imagens/sensores_no_mapa.jpeg)  
[Plataforma - Gráficos e filtro](Imagens/graficos_e_filtro.jpeg)
