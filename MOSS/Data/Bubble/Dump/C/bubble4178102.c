//2020 2.16 バブルソート

#include <stdio.h>
#define MAX 100

int main()
{
    int a,temp,cnt=0,cnt1=0;
    int i,j;
    int A[MAX];

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
    }
    while(1)
    {
        j=a-1;
        if(cnt1==j) break;
        while(j>=1)
        {
        if(A[j]<A[j-1])
        {
            cnt++;
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
        }
        j--;
        }
        cnt1++;
    }
    for(i=0;i<a;i++)
    {
        if(i==0) printf("%d",A[i]);
        else printf(" %d",A[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
