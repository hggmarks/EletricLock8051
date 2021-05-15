#include <8051.h>

void main(){
    EX0=1;
    EA=1;
    IT0=1;

    while(1){

    }
}

void IntExt0() __interrupt (0){

}


char varreLinha(char coluna){
    char retornaTecla=0;
    
    switch(coluna)
    {
    case 1:
        if(P0_4==0) retornaTecla = '1';
        if(P0_5==0) retornaTecla = '4';
        if(P0_6==0) retornaTecla = '7';
        if(P0_7==0) retornaTecla = '*';
        break;
    case 2:
        if(P0_4==0) retornaTecla = '2';
        if(P0_5==0) retornaTecla = '5';
        if(P0_6==0) retornaTecla = '8';
        if(P0_7==0) retornaTecla = '0';
        break;
    case 3:
        if(P0_4==0) retornaTecla = '3';
        if(P0_5==0) retornaTecla = '6';
        if(P0_6==0) retornaTecla = '8';
        if(P0_7==0) retornaTecla = '#';
        break;
    default:
        break;
    }
}

char lerTeclado(){
    char i;
    char teclaLida=0;

    for(i=1; i<4; i++){
        switch (i)
        {
        case 1:
            P0_0=0;
            if(teclaLida==0) {teclaLida = varreLinha(i);}
            P0_0=1;
        case 2:
            P0_1=0;
            if(teclaLida==0) {teclaLida = varreLinha(i);}
            P0_1=1;
            break;
        case 3:
            P0_2=0;
            if(teclaLida==0) {teclaLida = varreLinha(i);}
            P0_2=1;
        default:
            break;
        }
    }
    return teclaLida;
}