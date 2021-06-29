#include<cstdio>
void countingsort(int *A, int *B, int k, int n);
int main()
{
    int n, k = 10000;
    scanf("%d", &n);
    int A[n + 1], B[n + 1];
    for(int i = 1; i <= n; i++)
        scanf("%d", A + i);
    countingsort(A, B, k, n);
    for(int i = 1; i <= n; i++){
        if(i - 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
}
void countingsort(int *A, int *B, int k, int n)
{
    int C[k + 1];
    for(int i = 0; i <= k; i++)
        C[i] = 0;
    for(int i = 1; i <= n; i++)
        C[A[i]]++;
    for(int i = 1; i <= k; i++)
        C[i]+=C[i - 1];
    for(int i = 1; i <= n; i++){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}
