#include<stdio.h>

int selectionSort(int*, int);

int main()
{
  int a[100];
  int i, N, swapcnt;

  scanf("%d", &N);
  for(i=0;i<N;i++)
    {
      scanf("%d", &a[i]);
    }

  swapcnt = selectionSort(a, N);

  for(i=0;i<N;i++)
    {
      if(i)printf(" ");
      printf("%d", a[i]);
    }
  printf("\n%d\n", swapcnt);
  
  return 0;
}

int selectionSort(int* a, int N)
{
  int i, j, cnt=0, num, minj, flag;

  for(i=0;i<=N-1;i++)
    {
      minj = i;
      flag = 0;
      for(j=i;j<=N-1;j++)
	{	  
	  if(a[j]<a[minj])
	    {
	      minj = j;
	      flag = 1;
	    }
	}
      if(flag)
	{
	  num = a[i]; a[i] = a[minj]; a[minj] = num;
	  cnt++;
	}
    }
  
  return cnt;
}

