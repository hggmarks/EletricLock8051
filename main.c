#include <8051.h>

void main(){
    EX0 =  1;
    EA  =  1;
    IT0 =  1;
}

void IntExt0() __interrupt (0){

}

