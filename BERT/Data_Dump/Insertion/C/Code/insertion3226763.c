#include <stdio.h>

void output(int A[], int N) {
    int i;
    
    for (i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        
        printf("%d", A[i]);
    }
    
    printf("\n");
}

void insert(int A[], int N) {
    int i;
    int j, v;
    
    for (i = 1; i < N; i++) {
        v = A[i];
        
        j = i - 1;
        
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            
            j--;
        }
            
        A[j + 1] = v;
        
        output(A, N);
    }
}

int main(){
    int N, i;
    int A[100];
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    output(A, N);
    insert(A, N);
    
    return 0;
}

