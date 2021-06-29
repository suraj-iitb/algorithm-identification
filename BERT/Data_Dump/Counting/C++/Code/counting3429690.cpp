#include<cstdio>
#define nmax 2000000
#define Vmax 10000
int main()
{
    int n;
    scanf("%d",&n);
    int A[nmax];
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    int C[Vmax+1];
    for(int i=0;i<Vmax+1;i++)
    C[i]=0;

    for(int i=0;i<n;i++)
    C[A[i]]++;



    for(int i=1;i<=Vmax;i++)
    C[i]=C[i]+C[i-1];


    int B[nmax];
    for(int i=n-1;i>=0;i--)
    {
        B[C[A[i]]]=A[i];
        C[A[i]]--;

    }



    for(int i=1;i<n+1;i++)
    {
        if(i-1) printf(" ");
    printf("%d",B[i]);
    }
    printf("\n");
    return 0;
}

