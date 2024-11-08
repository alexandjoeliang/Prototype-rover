#include <HX711.h>
#include <loadcell.h>

#include <avr/io.h>


void initLoadCell(){

    DDRE |= ((1<<DDE0) | (1<<DDE1));

}


void readValue(){
    


}



