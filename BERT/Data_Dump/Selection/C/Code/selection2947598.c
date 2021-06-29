#include<stdio.h>

int main(){
    
    int n,i,j,tmp,count=0;
    int A[100];
    int min;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i;j<n;j++)
        {
         if(A[min] > A[j])
         {
             min = j;
         }    
        }
        tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
        if(i!=min)count++;
    }

    for (i=0;i<n;i++)
    {
        if(i>0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",count);

    return 0;
}
