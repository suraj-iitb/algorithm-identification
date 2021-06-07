//Depth first search

#include<stdio.h>
#define N 100
#define FIR 0
#define SEC 1
#define FIN 2

int n,remain,count;
int arr[N][N];
int state[N],first[N],second[N];

void countime(int l)
{
  int b;
  state[l] = SEC;
  first[l] = ++count;
 
  for(b = 1; b <= n; b++)
    {
      if(arr[l][b] == 0) continue;
      if(state[b] == FIR) countime(b);
    }
  state[l] = FIN;
  second[l] = ++count;
}

void worktime()
{
  int l;
  //initialize number & array
  count = 0;
  for(l = 1; l <= n; l++) state[l] = FIR;

  //start counting
  for(l = 1; l <= n; l++)
    {
      if(state[l] == FIR)
	{
	  countime(l);
	}
    }

  //output data
  for(l = 1; l <= n; l++)
    {
      printf("%d %d %d\n",l,first[l],second[l]);
    }
}


int main()
{
  int i, j, l, b;
  
  //input data
  scanf("%d",&n);
  for(i = 1; i <= n; i++)
    {
      for(j = 1; j <= n; j++)
	{
	  arr[i][j] = 0;
	}
    }
  
  for(i = 1; i <= n; i++)
    {
      scanf("%d %d",&l,&remain);
   
      for(j = 1; j <= remain; j++)
	{
	  scanf("%d",&b);

	  // printf("\n %d \n",b);

	  arr[l][b] = 1;
	}
    }

  //work
  worktime();

  return 0;
}

