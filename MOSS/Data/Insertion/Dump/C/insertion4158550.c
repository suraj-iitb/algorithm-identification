/*
 Algorithms and Data Structures 1
 Name: Ryuya Asada
 ID: s1260064
*/


#include <stdio.h>
#include <stdlib.h>


void peek(int, int[]);
void InsertionSort(int, int[]);


int main(int argc, char* argv[]) {
    int length = 0;
    int A[100];

    scanf("%d", &length);
    for(int i=0; i < length; ++i) {
        scanf("%d", &A[i]);
    }

    InsertionSort(length, A);
    peek(length, A);

    return 0;
}


void peek(int length, int A[]) {
    for(int i=0; i < length; ++i) {
        if(i != 0)
            printf(" ");
        
        printf("%d", A[i]);
    }
    printf("\n");
}


void InsertionSort(int length, int A[]) {
    for(int i=1; i < length; ++i) {
        int key = A[i];
        int j = i - 1;
        peek(length, A);
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = key;
    }
}

