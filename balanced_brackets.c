#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node{
    char bracket;
    struct Node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;

Node *createNode(char c);
void push(Stack *s,char c);
char pop(Stack *s);


int main() {
    int t; 
    char x;
    int pairs;
    int bol;
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        bol=0;
        Stack st;
        st.top=NULL;
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        pairs=strlen(s)/2;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                push(&st,s[i]);
            }
            else if(s[i]=='}' || s[i]==']' || s[i]==')'){
                x=pop(&st);
                if(x=='F'){
                    bol=0;
                }
                else{
                    switch(x){ 
                        case '(':
                            if(s[i]==')'){
                                bol++;
                            }
                            else{
                                bol--;
                            }
                            break;
                        case '[':
                            if(s[i]==']'){
                                bol++;
                            }
                            else{
                                bol--;
                            }
                            break;
                        case '{':
                            if(s[i]=='}'){
                                bol++;
                            }
                            else{
                                bol--;
                            }
                            break;

                    }
                }
            }
        }
        bol==pairs? printf("YES\n"):printf("NO\n");
        free(s);
    }
    return 0;
}


Node *createNode(char c){
    Node *n;
    n=(Node *)malloc(sizeof(Node));
    n->bracket=c;
    n->next=NULL;
    return n;
}

void push(Stack *s,char c){
    Node *n;
    n=createNode(c);
    n->next=s->top;
    s->top=n;
}

char pop(Stack *s){
    Node *aux;
    char x;
    aux=s->top;
    if(aux!=NULL){
        s->top=aux->next;
        x=aux->bracket;
        free (aux);
    }
    else{
        x='F';
    }
    return x;
}
