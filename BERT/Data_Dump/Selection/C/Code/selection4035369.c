#include<stdio.h>

#define N 100

int selectionSort(int *,int);

int main()
{
  int a[N],n,i,cnt;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
  {
    scanf("%d",&a[i]);
  }

  cnt = selectionSort(a,n);

  for(i = 0; i < n; i++)
  {
    if(i > 0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

int selectionSort(int *A, int n)
{
  int minj,j,i,temp,cnt=0;

  for(i = 0; i < n; i++)
  {
    minj = i;
    for(j = i; j < n; j++)
    {
      if(A[j] < A[minj])
      {
	minj = j;
      }
    }
    if(i != minj){
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      cnt++;
    }
  }
  
    return cnt;
}

