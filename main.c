#include <8051.h>

int PosDisplay = 0;
unsigned char Senha[] = {'1', '2', '3'}; // mude esses valores 123 para os que desejar como senha
unsigned char Input[] = {0,0,0};
unsigned char RespostaCerta[] = {'0', 'P', 'E', 'N'};
unsigned char RespostaErrada[] = {'L', '0', 'C', 'K'};
char Letra = 0;
__bit Trigger = 0;
__bit Bip = 0;

void main(){

    EX0=1;
    EA=1;
    IT0=1;

    while(1){

        P2=255;

        for(PosDisplay=0; PosDisplay<3;){

            if(Trigger!=0){

                Letra = lerTeclado();
                Input[PosDisplay] = Letra;
                caractereDisplay();
                Trigger = 0;
                PosDisplay++;

            }

            P1=255;

            switch (PosDisplay){
            case 0:
                P1_0 = 0;
                break;
            case 1:
                P1_1 = 0;
                break;
            case 2:
                P1_2 = 0;
                break;
            default:
                break;
            }
        }

        for(PosDisplay=0; PosDisplay<3; PosDisplay++){

            if([PosDisplay]!=Input[PosDisplay]){

                Bip = 0;
                P1_6 = Bip;

            }

        if(Bip == 1){
            P1_7 = 0;
        }

        for (PosDisplay = 0; PosDisplay < 4; PosDisplay++){

            if(Bip){
                Letra = RespostaCerta[PosDisplay];
            } else{
                Letra = RespostaErrada[PosDisplay];
            }

        switch(PosDisplay){
            case 0:
                P1_0 = 0;
                P2 = 0xff;
                break;
            case 1:
                P1_1 = 0;
                P2 = 0xff;
                break;
            case 2: 
                P1_2 = 0;
                P2 = 0xff;
                break;
            case 3:
                P1_3 = 0;
                P2 = 0xff;
                break;
            default:
                break;
        }

        caractereDisplay();
        P1 = 0xFF;

        }

        Bip = 1;

        }
    }
}

void IntExt0() __interrupt (0){

    EX0 = 0;
    P2 = 255;
    Trigger = 1;
    EX0 = 1;

}


char varreLinha(char coluna){

    char retornaTecla=0;
    
    switch(coluna){
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

    return retornaTecla;

}

char lerTeclado(){

    char i;
    char teclaLida=0;

    for(i=1; i<4; i++){

        switch (i)
        {
        case 1:
            P0_0=0;
            if(teclaLida==0) teclaLida = varreLinha(i);
            P0_0=1;
            break;
        case 2:
            P0_1=0;
            if(teclaLida==0) teclaLida = varreLinha(i);
            P0_1=1;
            break;
        case 3:
            P0_2=0;
            if(teclaLida==0) teclaLida = varreLinha(i);
            P0_2=1;
            break;
        default:
            break;
        }
    }

    return teclaLida;

}

void caractereDisplay(){

    switch(Letra)
    {
    case '0': 
        P2=0xC0;
        break;
    case '1':
        P2=0xF9;
        break;
    case '2':
        P2=0xA4;
        break;
    case '3':
        P2=0xB0;
        break;
    case '4':
        P2=0x99;
        break;
    case '5':
        P2=0x92;
        break;
    case '6':
        P2=0x82;
        break;
    case '7':
        P2=0xF8;
        break;
    case '8':
        P2=0x80;
        break;
    case '9':
        P2=0x90;
        break;
    case '*':
        P2=0x7F;
        break;
    case '#':
        P2=0xBF;
        break;
    case 'L':
        P2=199;
        break;
    case 'C': 
        P2=198;
        break;
    case 'K':
        P2=137;
        break;
    case 'P':
        P2=140;
        break;
    case 'E':
        P2=134;
        break;
    case 'N':
        P2=200;
        break;
    default:
        P2=0xFF;
        break;
    }

    P2=0xFF;

}