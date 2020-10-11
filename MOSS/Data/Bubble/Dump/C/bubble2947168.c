#include<stdio.h>

int main(){
    int n,i,j,tmp,flag,count=0;
    int A[100];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&A[i]); 
    }

    
 for(i=0;i<n;i++)
 {
    for(j=n-1;j>i;j--)
    {
        if(A[j] < A[j-1])
        {
            tmp = A[j-1];
            A[j-1] = A[j];
            A[j] = tmp;
            
            count++;
        }
    }
  }

    for(i=0;i<n;i++)
    {
        if(i>0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",count);

}
