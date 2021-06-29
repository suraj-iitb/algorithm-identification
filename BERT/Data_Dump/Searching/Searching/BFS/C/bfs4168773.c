//BFS

#include<stdio.h>
#include<stdlib.h>
#define N 100

int n,i,j;
int arr[N][N];
int imp[N];

void work(int x,int leng)
{
  int k;
  leng++;
  imp[x] = leng;

  for(k = 0; k < n; k++)
    {
      if(arr[x][k] == 1)
	{
	  if(imp[k] <= leng && imp[k] >= 0) continue;
	  work(k,leng);
	}
    }
}


int main()
{
  int l,b,remain;
  
  //input data
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d%d",&l,&remain);
      for(j = 0; j < remain; j++)
	{
	  scanf("%d",&b);
	  arr[l-1][b-1] = 1;
	}
    }

  //initialize number
  for(i = 0; i < n; i++) imp[i] = -1;

  //work
  work(0,-1);

  //output data
  for(i = 0; i < n; i++)
    {
      printf("%d %d\n",i+1,imp[i]);
    }

  return 0;
  
}

