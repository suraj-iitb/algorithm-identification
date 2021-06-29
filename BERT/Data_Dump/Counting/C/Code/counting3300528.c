#include <stdio.h>
#include <stdlib.h>
#define MAX 20000000
#define VMAX 1000000

int countingsort(int A[], int B[], int n, int C[]){
    int i;
    for (i = 0; i < n; i++){
        C[A[i]] += 1;
    }


    for(i  = 1; i <  VMAX; i++){
        C[i] = C[i-1] + C[i];
    }

    for(i = n-1; i >= 0; i--){
        B[C[A[i]]--] = A[i];
    }
    

    return 0;
}


int main(){
    int i, n;
    int C[VMAX];
    scanf("%d", &n);

    int A[n], B[n];

    for(i = 0; i < VMAX; i++){
        C[i] = 0;
    }

    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        B[i] = 0;
    }

    countingsort(A, B, n, C);

    for(i = 1; i <= n; i++){
        if(i != n){
            printf("%d", B[i]);
            printf(" ");
        } else{
            printf("%d\n", B[i]); 
        }
    }

    return 0;
}
