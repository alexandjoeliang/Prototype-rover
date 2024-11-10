/*#include <HX711.h>
#include "loadcell.h"

#include <avr/io.h>

HX711 scale;

void initLoadCell(){


    scale.begin(PINF0, PINF1);

}


long readValue(){
    if(scale.is_ready()){
        long reading = scale.read();
        return reading;
    }
    return 0;
}


*/
