#include<stdio.h>

void print(int A[],int n) {
    for (int i = 0; i < n; i++)
        printf("%d%c", A[i], i == n - 1 ? '\n' : ' ');
}
void insertsort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int v = A[i];
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print(A, n);
    }
}
int main() {
    int n, A[110];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    print(A, n);
    insertsort(A, n);
    return 0;
}
