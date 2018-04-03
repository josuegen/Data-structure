/*Ejercicio tipo ETS ó aplicaciones de estructuras de datos en donde debes encontrar el rectángulo más grande en un histograma usando 
una pila*/
/*Exercise of data structure application where you need to find the largest rectangle in a histogram using a stack*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

typedef struct node{
    int height;
    struct Node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;

void push(Stack *s,int data);
int pop(Stack *s);
int top(Stack *s);
void maxRectangle(int *arr, int n);

int main()
{
    int n,i;
    scanf("%i",&n);
    int *bars;
    bars=malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%i",&bars[i]);
    }
    maxRectangle(bars,n);

       return 0;
}

void maxRectangle(int *arr, int n){
    int area;
    int max=0;
    Stack s;
    s.top=NULL;
    int i;
    int pops;
    for(i=0;i<n;i++){
        if(s.top==NULL || arr[top(&s)]<=arr[i]){
            push(&s,i++);
        }
        else{
            pops=pop(&s);
            if(isEmpty(s)){
                area=arr[pops]*i;
            }
            else{
                area = arr[pops] * (i - top(&s) - 1);
            }
            if(area>max){
                max=area;
            }
        }
    }
    while(!isEmpty(s)){
            pops=pop(&s);
            if(isEmpty(s)){
                        area = arr[pops] * i;
            }
            else{
                        area = arr[pops] * (i - top(&s) - 1);
            }
            if(area > max){
                        max = area;
            }
    }
    printf("\n--> Max area rectangle: %i",max);
}



void push(Stack *s,int data){
    Node *n;
    n=(Node *)malloc (sizeof(Node));
    n->height=data;
    n->next=s->top;
    s->top=n;
}

int pop(Stack *s){
    int x;
    Node *aux=s->top;
    if(aux!=NULL){
        s->top=aux->next;
        x=aux->height;
        free(aux);
    }
    return x;
}

int top(Stack *s){
        return s->top->height;
}

int isEmpty(Stack *s){
    return s->top==NULL;
}

