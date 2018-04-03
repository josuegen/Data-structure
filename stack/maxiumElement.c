/*Basic operation with stack, maybe an application app*/
/*Operaciones básicas con pila, se puede usar como aplicaciones de pila*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;


void push(Stack *s, int data);
void pop(Stack *s);
int maxElement(Stack *s);


int main() {
    int i,op,data,re=0;
    int n;
    Stack s;
    s.top=NULL;
    do{
        system("cls");//remove this if using unix (linux,mac OS, etc)
        system("clear");//remove this if using windows
        printf("---- WELCOME ----\n\n");
        printf("1.Push a number\n");
        printf("2.Pop the stack\n");
        printf("1.Print the max element\n\n");
        printf("Choose an option (1-3): ");
        scanf("%d",&op);
        switch(op){
                case 1:
                    scanf("%i",&data);
                    push(&s,data);
                    break;
                case 2:
                    pop(&s);
                    break;
                case 3:
                    printf("---> The max element is: %i\n\n",maxElement(&s));
                    break;
                default:
                    printf("You didn't chose a correct option\n");
        }
        printf("----- To exit type 2, to continue type any other number  -----\n\n");
        scanf("%i",&re);
    }while(re!=2);
    return 0;
}

void push(Stack *s, int data){
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=data;
    if(s->top==NULL){
        s->top=n;
    }
    else{
        n->next=s->top;
        s->top=n;
    }
}

void pop(Stack *s){
    if(s->top){
        Node *aux;
        aux=s->top;
        s->top=aux->next;
        free(aux);
    }
}

int maxElement(Stack *s){
    Node *aux;
    int max=0;
    aux=s->top;
    while(aux){
        if(aux->data>max){
            max=aux->data;
        }
        aux=aux->next;
    }
    free(aux);
    return max;
}

