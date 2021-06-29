#include<stdio.h>

#define N 100

void Insort(void);

int n = 0,arr[N];
int i = 0;
int v = 0;
int j = 0;
int k = 0;
int main()
{

//input data

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&arr[i]);
    }

  //assignment Insort

    printf("%d",arr[0]);
      for(k = 1; k < n ; k++)
	{
	  printf(" %d",arr[k]);
	}
      printf("\n");
  Insort();

  return 0;
}

void Insort(void)
{
  for(i = 1; i <= n - 1; i++)
    {
      v = arr[i]; 
      j = i - 1;

      for(; j >= 0 && arr[j] > v ;)
	{
	  arr[j+1] = arr[j];
	  j--;
	  //printf("j=%d\n",j);
	}
      arr[j+1]=v;
      /*
       if(j == -1 || arr[j] <= v)
	    {
	      arr[j+1] = v;
	      break;
	      }*/

      printf("%d",arr[0]);
      for(k = 1; k < n ; k++)
	{
	  printf(" %d",arr[k]);
	}
      printf("\n");
    }
     
}


