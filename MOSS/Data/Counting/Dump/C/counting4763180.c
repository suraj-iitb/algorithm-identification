#define N 2000005
#include <stdio.h>

int A[N];
int B[N];
int C[10005];

//输入数组，输出数组，数组长度，元素最大值
void CountingSort(int A[], int B[], int n, int k) {
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] = C[i - 1] + C[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}


int main() {
    int n = 0;    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    CountingSort(A, B, n, 10005);
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
}
