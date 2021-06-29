#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N,i,j,key,k;
  int *array;

  /* 入力 */
  scanf("%d",&N);
  if(N >100 || N < 1) exit(0);
  array = (int *)malloc(sizeof(int) * N);
  if(array == NULL) exit(0);
  for(i = 0;i < N;i++){
    scanf("%d",&array[i]);
  }

  /* 出力 */
  for(k = 0;k < N;k++){
    printf("%d",array[k]);
    if (k != N-1) printf(" ");
  }
  printf("\n");
 
  /* sort */
  for(i = 1;i <= N-1;i++){
    key = array[i];
    j = i - 1;
    while(j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
    /* 出力 */
    for(k = 0;k < N;k++){
      printf("%d",array[k]);
      if (k != N-1) printf(" ");
    }
    printf("\n");
  }
    
  return 0;
}
