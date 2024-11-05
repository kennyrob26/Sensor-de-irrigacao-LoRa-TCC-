#ifndef __DEBUG__
    #define __DEBUG__

    //#define DEBUG

    #ifdef DEBUG
        #define DEBUG_PRINT(x)          Serial.print(x)
        #define DEBUG_PRINTLN(x)        Serial.println(x)
        #define DEBUG_SERIAL_BEGIN(x)   Serial.begin(x)
        #define DEBUG_SERIAL_END()      Serial.end();
    #else
        #define DEBUG_PRINT(x)  
        #define DEBUG_PRINTLN(x)   
        #define DEBUG_SERIAL_BEGIN(x)
        #define DEBUG_SERIAL_END()
    #endif
#endif
