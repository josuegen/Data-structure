/*La operación 'left rotation' en un arreglo the tamaño n, mueve cada elemento del arreglo una unidad a la izquierda.
Por ejemplo, si se aplican 2 operaciones 'left rotation' en el arreglo [1,2,3,4,5], entonces el arreglo quedaría como [3,4,5,1,2]
Se da un arreglo de n enteros y un numer d, aplica d numero de operaciones 'left rotation' en el arreglo.
Después se imprime el arreglo actualizado en una sola linea, cada elemento separado por un espacio.
*/

/*A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. 
For example, if 2 left rotations are performed on array [1,2,3,4,5] , then the array would become [3,4,5,1,2].
Given an array of n integers and a number, d , perform d left rotations on the array. 
Then print the updated array as a single line of space-separated integers.
*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* leftRotation(int a_size, long rot, int* a,long now) {
    int *ar=malloc(sizeof(int) * a_size);
    int size=a_size;
    long rotaciones=rot;
    long nowa=now;
    for(int i=0;i<size;i++){
        if(i==0){
            ar[a_size-1]=a[i];
        }
        else{
            ar[i-1]=a[i];
        }
    }
    nowa++;
    if(nowa==rot){
        return ar;
    }
    else{
        return (leftRotation(size,rotaciones,ar,nowa));
    }
}



int main() {
    int n; 
    long d; 
    scanf("%i %ld", &n, &d);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
       scanf("%i",&a[a_i]);
    }
    int* result = leftRotation(n, d, a,0);
    for(int result_i = 0; result_i < n; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }



    return 0;
}
