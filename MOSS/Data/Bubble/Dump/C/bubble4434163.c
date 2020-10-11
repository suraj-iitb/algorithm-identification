#include <stdio.h>
int cnt = 0;

void bubbleSort(int A[],int n) {
    int flag = 1, tmp;
    while (flag) {
        flag = 0;
        for (int i = n-1; i > 0; i--) {
            if (A[i] < A[i-1]) {tmp = A[i]; A[i] = A[i-1]; A[i-1] = tmp; flag = 1; cnt++;}
        }
    }
}

int main(void){
    int n, A[100];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    bubbleSort(A, n);
    
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    
    printf("\n");
    printf("%d", cnt);
    printf("\n");
    
    return 0;
}

