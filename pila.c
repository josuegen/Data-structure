#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct nodo{
    int dato;
    struct Nodo *sig;
}Nodo;

typedef struct pila{
    Nodo *top;
}Pila;



int main()
{
    int op=0,repetir=0,valor=0;
    Pila p;
    iniciarPila(&p);
    do{
        system("cls");
        printf("MENU DE PILA DINAMICA\n\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Imprimir Pila\n");
        scanf("%i",&op);
        switch(op){
            case 1:
                printf("-- P U S H --\n");
                printf("Ingresa el valor a empujar: ");
                scanf("%i",&valor);
                push(&p,valor);
                break;
            case 2:
                printf("-- P  O  P --\n");
                pop(&p);
                break;
            case 3:
                leerPila(&p);
                break;
        }
    printf("Otra operacion? (1=SI, 2=NO)\n");
    scanf("%i",&repetir);
    }while(repetir!=2);
    return 0;
}

void iniciarPila(Pila *p){
    p->top=NULL;
}

int pilaVacia(Pila *p){
    return p->top==NULL;
}

Nodo *creaNodo(int num){
    Nodo *n;
    n=(Nodo *)malloc(sizeof(Nodo));
    if(n==NULL){
        printf("NO_MEMORY");
    }
    else{
        n->dato=num;
        n->sig=NULL;
    }
    return n;
}
void push(Pila *p,int num){
    Nodo *n;
    n=creaNodo(num);
    n->sig=p->top;
    p->top=n;
    printf("-----------\n");
    printf("-->  El valor %i se anadio a la pila. \n",p->top->dato);
}

void pop(Pila *p){
    Nodo *aux;
    if(pilaVacia(p)){

        printf("-->  La pila esta vacia! \n");
    }
    else{
        aux=p->top;
        p->top=aux->sig;
        printf("-----------\n");
        printf("-->  El valor %i salio de la pila. \n",aux->dato);
    }
    free(aux);
}

void leerPila(Pila *p){
    if(pilaVacia(p)){
        printf("-->  La pila esta vacia! \n");
    }
    else{
        Nodo *temp;
        temp=p->top;
        printf("-----------\n");
        printf("P I L A \n");
        while(temp->sig!=NULL){
            printf("-> %i,\n",temp->dato);
            temp=temp->sig;
        }
        if(temp->sig==NULL){
            printf("-> %i,\n",temp->dato);
        }
    }
}
