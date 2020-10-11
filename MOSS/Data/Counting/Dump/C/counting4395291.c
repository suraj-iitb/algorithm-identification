#include<stdio.h>
int main(void)
{
  int n,i,max=0;
  scanf("%d",&n);
  int A[n],B[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&A[i]);
    if(A[i]>max) max=A[i];
  }
  int C[max+1];
  //Counting_Sort
  for(i=0;i<=max;i++) C[i]=0;
  for(i=0;i<n;i++) C[A[i]]++;
  //for(i=0;i<=max;i++) printf("%d:%d ",i,C[i]);
  for(i=1;i<=max;i++)
  {
    C[i]=C[i]+C[i-1];
  }
  //for(i=0;i<=max;i++) printf("%d:%d ",i,C[i]);
  //printf("\n");
  for(i=n-1;i>=0;i--)
  {
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<=n;i++) 
  {
      if(i==n) printf("%d",B[i]);
      
    else    printf("%d ",B[i]);
  }
  printf("\n");
  return 0;
}

