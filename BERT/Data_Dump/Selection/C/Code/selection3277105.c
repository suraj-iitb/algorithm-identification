#include <stdio.h>
#define N 100
int main()
{
  int cnt=0,i,mini,a,A[N],n,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d",&A[i]);
  for(i=0;i<=n-1;i++)
  {
    mini = i;
    for(j=i;j<=n-1;j++)
    {
      if(A[j] < A[mini])
        {
          mini = j;
        }
    }
      if(A[i] != A[mini])
        cnt++;
      a = A[i];
      A[i] = A[mini];
      A[mini] = a;
  }
  for(i=0;i<n;i++)
  {
    printf("%d",A[i]);
    if(i!=n-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);
}
