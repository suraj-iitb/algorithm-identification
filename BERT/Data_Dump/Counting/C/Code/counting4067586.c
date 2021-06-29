#include<stdio.h>
#define N1 2000001
#define N2 2000001
#define M 10001

int array[N1], sort_array[N2], counting[M];

int main(){

  int i, n, k;

  for(i = 1; i < N2; i++)sort_array[i] = 0;
  for(i = 1; i < M; i++)counting[i] = 0;
  
  scanf("%d",&n);

  for(i = 1; i <= n; i++)
    {
      scanf("%d",&array[i]);
      counting[array[i]]++;
    }

  for(i = 0; i < M; i++)
    {
      counting[i + 1] += counting[i];
      /*
	for(k = 1; k < n; k++)printf("%d ",counting[k]);
	printf("\n");
      */
    }
  
  for(i = n; i >= 1; i--)
    {
      /*
	printf("--------------------------------\n");
	printf("counting\n\n");
	for(k = 1; k < n; k++)printf("%d ",counting[k]);
	printf("\n");
	printf("--------------------------------\n\n");
      */
      sort_array[counting[array[i]]] = array[i];
      counting[array[i]]--;
    }

  for(i = 1; i <=  n; i++)
    {
      if(i != 1)printf(" ");
      printf("%d",sort_array[i]);
      
    }
  printf("\n");
  
  
  
  return 0;
}

