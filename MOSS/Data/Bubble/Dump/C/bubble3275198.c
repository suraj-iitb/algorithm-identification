#include<stdio.h>

int bubbleSort(int*, int);

int main()
{
  int a[100];
  int i, N, swapcnt;

  scanf("%d", &N);
  for(i=0;i<N;i++)
    {
      scanf("%d", &a[i]);
    }

  swapcnt = bubbleSort(a, N);

  for(i=0;i<N;i++)
    {
      if(i)printf(" ");
      printf("%d", a[i]);
    }
  printf("\n%d\n", swapcnt);
  
  return 0;
}

int bubbleSort(int* a, int N)
{
  int flag=1, i=0, j, cnt=0, num;

  while(flag)
    {
      flag = 0;
      for(j=N-1;j>=i+1;j--)
	{
	  if(a[j]<a[j-1])
	    {
	      num = a[j-1]; a[j-1] = a[j]; a[j] = num;
	      cnt++;
	      flag = 1;
	    }
	}
      i++;
    }
  
  return cnt;
}

