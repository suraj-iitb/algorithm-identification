#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,j,N,minj,sub,count = 0;
  int *array;

  scanf("%d",&N);
  array = (int *)malloc(sizeof(int) * N);
  if(array == NULL) exit(0);

  for(i = 0;i < N;i++){
    scanf("%d",&array[i]);
  }

  for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(array[j] < array[minj]) minj = j;
    }
    sub = array[minj];
    array[minj] = array[i];
    array[i] = sub;
    if(array[i] != array[minj]) count++;
  }

  for(i = 0;i < N;i++){
    printf("%d",array[i]);
    if(i != N-1) printf(" ");
  }

  printf("\n");
  printf("%d\n",count);

  free(array);

  return 0;
}
