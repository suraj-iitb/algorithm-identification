#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


void countingsort(int *A, int *B, int k, int n){
    int i,j;
    int C[1000000];
    for(i=0;i<k+1;i++) C[i]=0;

    for(i=0;i<n;i++) C[A[i]]++;

    for(i=1;i<k+1;i++){
        C[i]=C[i] + C[i-1];
    }

    for(i=n-1;i>=0;i--){
        B[C[A[i]]-1] = A[i];
     // printf("%d\n", A[i]);
        C[A[i]]--;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int)*n);
    int *B = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++) scanf("%d", &A[i]);
    countingsort(A, B, 10000, n);
    for(int i=0;i<n;i++){
        if(i==n-1)printf("%d", B[i]);
        else printf("%d ", B[i]);
    }
    printf("\n");
    free(A);
    free(B);

}
