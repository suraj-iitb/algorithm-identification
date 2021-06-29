#include<stdio.h>
int main()
{
    int i=0, j, k=0, n;
    scanf("%d", &n);
    int A[n], B[n], C[2000001];
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    for(i = 0; i < 2000001; i++) C[i] = 0;

    for(i = 0; i < n; i++) C[A[i]]++;
    i = 0;
    k = 0;
    while(i < n) {
    for(j = 0; j < C[k]; j++) {
        B[i] = k;
        i++;
    }
    k++;
    }

    for(i = 0; i < n - 1; i++) printf("%d ", B[i]);
    printf("%d\n", B[n-1]);
    return 0;
}


