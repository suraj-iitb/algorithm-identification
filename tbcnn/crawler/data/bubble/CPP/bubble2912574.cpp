# include <stdio.h>

int bubbleSort(int *A, int N) {
    int flag = 1, count=0;
    while(flag) {
        flag = 0;
        for (int j=N-1; j>0; j--) {
            if (A[j] < A[j-1]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
                flag = 1;
            }
        }
    }
    return count;
}

void outputArray(int *A, int N) {
    printf("%d", A[0]);
    for (int i=1; i<N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    
    int count = bubbleSort(a, n);
    outputArray(a, n);
    printf("%d\n", count);
    
    return 0;
}
