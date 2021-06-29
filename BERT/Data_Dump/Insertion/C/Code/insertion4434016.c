#include <stdio.h>

void insertionSort(int A[], int n) {
    int j, v;
    for (int i = 1; i < n; i++) {
        for (int k = 0;k < n; k++) {
            if (k) printf(" ");
            printf("%d", A[k]);
        }
        printf("\n");
        
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main(void){
    int n, A[100];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    insertionSort(A, n);
    
    for (int k = 0;k < n; k++) {
        if (k) printf(" ");
        printf("%d", A[k]);
    }
    printf("\n");
        
    return 0;
}
