#include <stdio.h>
#include <stdlib.h>
#define VMAX 10001

int main(void){
    unsigned short *A, *B;
    int n, i;
    int C[VMAX];
    
    scanf("%d", &n);
    A = malloc(sizeof(int) * n + 1);
    B = malloc(sizeof(int) * n + 1);

    for (i = 0; i < VMAX; i++){
        C[i] = 0;
    }

    for (i = 0; i < n; i++){
        scanf("%hd", &A[i]);
        C[A[i]] += 1;
       
    }

    for (i = 0; i < n; i++){
        // printf("%d  ", C[i]);
        // printf("%d ", *A);
        // A++;
    }
    

    for (i = 1; i < VMAX + 1; i++){
        C[i] = C[i - 1] + C[i];
    }

    // check
    // for (i = 0; i < 10; i++){
    //     printf("%d  ", C[i]);
    // }
    // putchar('\n');

    for (i = n - 1; i >= 0; i--){
        
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (i = 0; i < n - 1; i++){
        printf("%d ", B[i]);
    }
    printf("%d\n", B[n - 1]);
    
    return 0;

}

/*
7 
2 5 1 3 2 3 0
*/
