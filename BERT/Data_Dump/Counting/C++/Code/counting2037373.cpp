#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 2000001
#define VMAX 10000
#define SENTINEL 2000000000

int C[VMAX + 1];

void CountingSort(int A[], int B[], int n, int k){
    /*
    A???1?§????????????????, ????????????n
    A??????????´??????????k??\???
     */
    int i,j;
    for(i = 0; i <= k; i++) C[i] = 0;

    for(j = 1; j <= n; j++) C[A[j]]++;

    for(i = 1; i <= k; i++) C[i] = C[i] + C[i-1];

    for(j = n; j >= 1; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(int argc, char const *argv[])
{
    int n, i, j, A[MAX+1], B[MAX+1];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i+1]);
    }

    CountingSort(A, B, n, VMAX);
    for (int i = 1; i <= n; ++i)
    {
        if(i>1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
