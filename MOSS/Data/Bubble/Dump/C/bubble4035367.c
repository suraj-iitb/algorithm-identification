#include<stdio.h>

#define N 100

int bubbleSort(int *,int);

int main()
{
  int a[N],n,i,cnt;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
  {
    scanf("%d",&a[i]);
  }

  cnt = bubbleSort(a,n);

  for(i = 0; i < n; i++)
  {
    if(i > 0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

int bubbleSort(int *A, int n)
{
  int flag,j,temp,cnt=0;

  flag = 1;
  j = 0;

  while(flag == 1){
    flag = 0;
    for(j = n-1; j > 0; j--)
    {
      if(A[j] < A[j-1])
      {
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	cnt++;
      }
    }
  }
  
    return cnt;
}

