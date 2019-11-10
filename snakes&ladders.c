#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

typedef struct casilla{
    int numerocasilla;
    struct Casilla *destino;
}Casilla;

void iniciarJuego();

main(){
    iniciarJuego();
}

void iniciarJuego(){
    printf("\n\t\t\t --------------------------------------------------\n");
    printf("\t\t\t|               SERPIENTES Y ESCALERAS             |\n");
    printf("\t\t\t --------------------------------------------------\n\n\n\n");

    srand(time(NULL));
    int i=0;
    Casilla casillas[25];
    int tirarDado=0;
    int posicionActual=1;
    Casilla *ficha;
    for(i=0;i<25;i++){
        casillas[i].numerocasilla=i+1;
    }
    for(i=0;i<25;i++){
        switch(i){
        case 2:
            casillas[i].destino=&casillas[10];
            break;
        case 5:
            casillas[i].destino=&casillas[16];
            break;
        case 8:
            casillas[i].destino=&casillas[17];
            break;
        case 9:
            casillas[i].destino=&casillas[11];
            break;
        case 13:
            casillas[i].destino=&casillas[3];
            break;
        case 18:
            casillas[i].destino=&casillas[7];
            break;
        case 21:
            casillas[i].destino=&casillas[19];
            break;
        case 23:
            casillas[i].destino=&casillas[15];
            break;
        default:
            casillas[i].destino=NULL;
        }
    }
    printf("--> ");
    system("PAUSE");
    printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");
    do{

        int dado=(rand()%6)+1;
        printf("--------------------------------------\n");
        printf("-> Te encunetras en la casilla: %d\n",posicionActual);
        printf("-> En el dado obtuviste: %d\n",dado);
        if((posicionActual+dado)>25){
            int excedente=-(25-(posicionActual+dado));
            //printf("Excedente: %d\n",excedente);
            posicionActual=25-excedente;
            printf("->Has llegado a la casilla: %d\n",posicionActual);
            if(casillas[(posicionActual-1)].destino!=NULL){
                ficha=casillas[(posicionActual-1)].destino;
                if((ficha->numerocasilla)>posicionActual){
                    printf("     !CASILLA CON ESCALERA!\n");
                }
                else{
                    printf("     !CASILLA CON SERPIENTE!\n");
                }
                posicionActual=ficha->numerocasilla;
                printf("-> Has llegado a la casilla: %d\n",posicionActual);
            }
        }
        else{
            posicionActual=posicionActual+dado;
            printf("-> Has llegado a la casilla: %d\n",posicionActual);
            if(casillas[(posicionActual-1)].destino!=NULL){
                ficha=casillas[(posicionActual-1)].destino;
                if((ficha->numerocasilla)>posicionActual){
                    printf("     !CASILLA CON ESCALERA!\n");
                }
                else{
                    printf("     !CASILLA CON SERPIENTE!\n");
                }
                posicionActual=ficha->numerocasilla;
                printf("-> Has llegado a la casilla: %d\n",posicionActual);
            }
        }
        printf("\n-------------    Presione 1, para volver a tirar dado.   -------------\n");
        scanf("%i",&tirarDado);
    }while(tirarDado==1 && (posicionActual)<25);
}
