#include<stdio.h>


void dayin(int A[],int n) {
    for (int i = 0; i < n; i++)
        printf("%d%c", A[i], i == n - 1 ? '\n' : ' ');
}

void charu(int A[], int n) {
   
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int v = A[i];
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        dayin(A, n);
    }
}
int main() {
    int n, A[110];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    dayin(A, n);
    charu(A, n);
    return 0;
}
