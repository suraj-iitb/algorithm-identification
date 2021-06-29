#include<stdio.h>

int bubbleSort(int A[], int n) // N 個の要素を含む 0-オリジンの配列 A
{
  int j,B[2];
  int flag = 1;
  int count=0;

  while(flag==1)
  {
    flag = 0;
    for(j = n-1; j>0; j--)
    {
      if(A[j] < A[j-1])
      {
        B[0]=A[j];
        B[1]=A[j-1];
        A[j]=B[1];
        A[j-1]=B[0];
        count++;
        flag = 1;
      }
    }

  }
  return count;
}


int main()
{
  int i,c,n,A[100];
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&A[i]);

  c = bubbleSort(A, n);

  for(i=0; i<n; i++)
  {
    printf("%d",A[i]);
    if(i < n-1) printf(" ");
  }

  printf("\n%d\n",c);

  return 0;
}
