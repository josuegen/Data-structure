/*Programa que lee una serie de palabras y las almacaena, para después leer otra serie de palabras y muestra cuantas veces aparecen estas 
palabras en la primera serie
*/
/*
There is a collection of N strings ( There can be multiple occurences of a particular string ). 
Each string's length is no more than 20 characters. There are also Q queries. 
For each query, you are given a string, and you need to find out how many times this string occurs in the given collection of N strings.
/*

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct str{
    char word[20];
}Str;

typedef struct qr{
    char query[20];
    int cantidad;
}Qr;
int main() {
    int n_words=0;
    int n_querys=0;
    scanf("%i",&n_words);
    Str s[n_words];
    for(int i=0;i<n_words;i++){
        fflush(stdin);
        scanf("%s",s[i].word);
    }
    scanf("%i",&n_querys);
    Qr q[n_querys];
    int queries[n_querys];
    for(int i=0;i<n_querys;i++){
        fflush(stdin);
        scanf("%s",q[i].query);
        q[i].cantidad=0;
    }
    
    for(int i=0;i<n_querys;i++){
        for(int j=0;j<n_words;j++){
            if((strcmp(q[i].query,s[j].word))==0){
                q[i].cantidad++;
            }
        }
    }
    for(int i=0;i<n_querys;i++){
        printf("%i\n",q[i].cantidad);
    }
    return 0;
}
