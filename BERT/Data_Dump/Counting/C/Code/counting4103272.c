#include <stdio.h>
#include <stdlib.h>
#define NMAX 2000000
#define VMAX 10000

int main(){
    unsigned short *A, *B;
    int C[VMAX+1];
    int n, i, j;

    scanf("%d", &n);

    A = malloc(sizeof(short)*n+1);
    B = malloc(sizeof(short)*n+1);

    //initialize the count table
    for(i = 0; i<=VMAX; i++) C[i] = 0;
    //input
    for(i = 0; i<n; i++) scanf("%hd", &A[i]);
    //making frequency table
    for(i = 0; i<n; i++) C[A[i]]++;
    //making scheme 
    for(i = 1; i<=VMAX; i++) C[i] += C[i-1];
    //sort
    for(i = n-1; i>=0; i--){
	B[C[A[i]]] = A[i];
	C[A[i]]--;
    }
    //print
    for(i = 1; i<n+1; i++){
	printf("%d", B[i]);
	if(i < n) printf(" ");
    }
    printf("\n");
    return 0;
}

