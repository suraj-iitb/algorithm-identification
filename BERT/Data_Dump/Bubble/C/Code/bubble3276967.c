#include <stdio.h>
#define N 100
int main()
{
  int cnt=0,flag,i,a,A[N],n,j;
  flag = 1;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d",&A[i]);
  while(flag)
  {
    flag = 0;
    for(j=n-1;j>=1;j--)
    {
      if(A[j] < A[j-1])
      {
        a = A[j];
        A[j] = A[j-1];
        A[j-1] = a;
        flag = 1;
        cnt++;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    printf("%d",A[i]);
    if(i!=n-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);
}
