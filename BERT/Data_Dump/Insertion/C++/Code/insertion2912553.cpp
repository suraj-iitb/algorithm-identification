# include <stdio.h>

void outputArray(int *A, int N) {
    printf("%d", A[0]);
    for(int i=1; i<N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int N) {
    for(int i=1; i<N; i++) {
        int v = A[i];
        int j = i - 1;
        while(j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        outputArray(A, N);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    
    outputArray(a, n);
    insertionSort(a, n);
    
    return 0;
}

