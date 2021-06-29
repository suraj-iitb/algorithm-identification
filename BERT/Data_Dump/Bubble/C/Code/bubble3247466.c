#include <stdio.h>

#define N 100

void trace(int A[], int n){
    for(int i = 0; i < n; i++){
            printf("%d", A[i]);
            if(i != n - 1){
                printf(" ");
            }

    }
    printf("\n");
}
 
int bubblesort(int A[], int n){
    int j, t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        j = n - 1;
        while(j > i){
            /* exchange */
            if(A[j - 1] >  A[j]){
                t = A[j - 1];
                A[j - 1] = A[j];
                A[j]  = t;
                cnt ++; 
                
            }
            j--;
        }

    }

    trace(A, n);
    return cnt;
}

int main(){
    int n, i;
    int A[N + 1];

    scanf("%d", &n);
    for (i = 0; i < n; i++ ) scanf("%d", &A[i]);

    printf("%d\n", bubblesort(A, n));

    return 0;
}
