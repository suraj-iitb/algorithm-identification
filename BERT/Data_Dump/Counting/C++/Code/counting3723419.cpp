#include<cstdio>
int A[2000005];
int C[10005];
int B[2000005];
void CountingSort(int A[], int B[], int n)
{
    int k = 0;
    for(int i=0; i<n; i++)
    {
        if(k < A[i]) k = A[i];
        C[A[i]]++;
    }
    for(int i=1; i<=k; i++)
    {
        C[i] = C[i] + C[i-1];
    }
    for(int i =n-1; i>=0; i--)
    {
        B[C[A[i]]-1]= A[i];
        C[A[i]] --;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    CountingSort(A,B,n);
    //printf("%d",C[A[n-1]]);
    for(int i=0; i<n; i++)
    {
        if(i) printf(" ");
        printf("%d",B[i]);
    }
    printf("\n");

    return 0;
}
