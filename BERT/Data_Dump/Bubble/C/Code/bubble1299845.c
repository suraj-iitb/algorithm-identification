#include <stdio.h>

#define MAX 100

int bubbleSort(int *,int);

int main(void)
{
  int array[MAX],N,i,count;

  scanf ("%d",&N);
  for (i = 0 ; i < N ; i++)
    scanf ("%d",&array[i]);

  count = bubbleSort(array,N);

  for (i = 0 ; i < N ; i++){
    printf ("%d",array[i]);
    if (i < N-1)
      printf (" ");
    else printf ("\n");
  }

  printf ("%d\n",count);

  return 0;
}

int bubbleSort(int *array,int N)
{
  int flag,j,c,count=0;

  flag = 1; //逆の隣接要素が存在する

  while (flag){
    flag = 0;
    for (j = N-1 ; j >= 1 ; j--){
      if (array[j] < array[j-1]){
	c = array[j];
	array[j] = array[j-1];
	array[j-1] = c;
	flag = 1;
	count++;
      }
    }
  }
  return count;
}
