#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000


//void CoutingSort(int [], int n);

int main(){
     int *A, *B;
    int  n,i, j;
    int C[VMAX+1];
    scanf("%d", &n);

    A = malloc(sizeof(int)*n+1);
    B = malloc(sizeof(int)*n+1);



    for ( i = 0; i <= VMAX; i++ ) C[i] = 0;

    for(i=0; i<n; i++){
        scanf("%d", &A[i+1]);
         C[A[i+1]]++;
    }

    for(i=1;i<=VMAX; i++){
        C[i] = C[i] + C[i-1];
    }

    for(j=n; j>0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }



  //  CoutingSort(A, n);

    for( i=1; i<=n; i++){
        if(i>1) printf(" ");
        printf("%d",B[i]);
    }
    printf("\n");

    return 0;
}

