#include <stdio.h>

int selectionSort(int *A, int N) {
    int count=0;
    
    for (int i=0; i<N; i++) {
        int minj = i;
        int flag = 0;
        for (int j=i; j<N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
                flag = 1;
            }
        }
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        if(flag) count++;
    }
    
    return count;
}

void outputArray(int *A, int N) {
    printf("%d", A[0]);
    for (int i=1; i<N; i++) printf(" %d", A[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    
    int count = selectionSort(a, n);
    outputArray(a, n);
    printf("%d\n", count);
    
    return 0;
}
