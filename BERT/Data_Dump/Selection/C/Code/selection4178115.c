//2020 2.16 選択ソート

#include <stdio.h>
#define MAX 100

int main()
{
    int A[MAX];
    int i,j;
    int a,min,temp,temp2,flag=0,cnt=0;

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
    }
    
    for(i=0;i<a;i++)
    {
        min = A[i];
    for(j=i+1;j<a;j++)
    {
        if(min>A[j]) {min = A[j]; temp = j; flag=1;}
    }

    if(flag==1)
    {
    temp2 = A[i];
    A[i] = min;
    A[temp] = temp2;
    cnt++;
    flag=0;
    }
    
    }
    for(i=0;i<a;i++)
    {
        if(i==0) printf("%d",A[i]);
        else printf(" %d",A[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
