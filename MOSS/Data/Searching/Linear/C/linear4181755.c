//2020 4.18 Linear Search

#include <stdio.h>
#define MAX1 10000
#define MAX2 500

int main()
{
    int a,b,cnt=0;
    int i,j;
    int A[MAX1],B[MAX2];

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
    }

    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&B[i]);
        for(j=0;j<a;j++)
        {
            if(A[j]==B[i]) {cnt++; break;}
        }
    }
    printf("%d\n",cnt);
}
