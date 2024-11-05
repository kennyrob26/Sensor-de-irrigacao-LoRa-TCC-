#ifndef __SENSORES_SOLO__
    #define __SENSORES_SOLO__

    #include "DEBUG.h"
    
    #include <Arduino.h>

    void iniciarSensorSolo();
    int8_t getUmidadeSolo();
    float lerSensor(uint8_t sensor);

#endif