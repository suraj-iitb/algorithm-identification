#include <stdio.h>

#define MAX 100

int selectionSort(int *,int);

int main (void)
{
  int array[MAX],N,i,count;

  scanf ("%d",&N);
  for (i = 0 ; i < N ; i++)
    scanf ("%d",&array[i]);

  count = selectionSort(array,N);

  for (i = 0 ; i < N ; i++){
    printf ("%d",array[i]);
    if (i < N-1)
      printf (" ");
    else printf ("\n");
  }
  
  printf ("%d\n",count);
  return 0;
}

int selectionSort(int *array, int N)
{
  int i,j,minj,a,b,count=0;

  for (i = 0 ; i < N ; i++){
    minj = i;
    for (j = i ; j < N ; j++){
      if (array[j] < array[minj]){
	minj = j;
      }
    }
    a = array[i];
    b = array[minj];
    array[i] = b;
    array[minj] = a;
    if (a != array[i])
      count++;
  }

  return count;
}
