/*
AOJ - ALDS1_1_A
Date: 20190307
Author: Mikoron * ♡mikoiwate_351♡
*/

#define N 101

#include<stdio.h>

void Print_Array(short A[], short num_of_A);

int main(void) {
        short i, j, num_of_A, A[N], key;

        scanf("%hd", &num_of_A);
        for(i = 0; i < num_of_A; i++) {
                scanf("%hd", &A[i]);
        }

        for(i = 1; i < num_of_A; i++) {
                Print_Array(A,num_of_A);
                key = A[i];
                j = i-1;
                while(j >= 0 && A[j] > key) {
                        A[j+1] = A[j];
                        j--;
                }
                A[j+1] = key;
        }
        Print_Array(A,num_of_A);
        return 0;
}

void Print_Array(short A[], short num_of_A) {
        short i;

        for(i = 0; i < num_of_A; i++) {
                if(i > 0) printf(" ");
                printf("%hd", A[i]);
        }
        printf("\n");
}

