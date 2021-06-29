#include <stdio.h>
#define N 100

int main(){
  int array_size, numbers[N], key, i, j, k;
  
  scanf("%d",&array_size);

  for(i = 0; i < array_size; i++){
    scanf("%d",&numbers[i]);
  }
  for(j = 0; j < array_size - 1; j++){
    printf("%-d ",numbers[j]);
  }
  
  printf("%-d\n",numbers[array_size - 1]);

  for(i = 1; i < array_size; i++){
    key = numbers[i];
    j = i - 1;
    while((j >= 0) && (numbers[j] > key)){
      numbers[j + 1] = numbers[j];
      j--;
      numbers[j + 1] = key;
    }
    for(k = 0; k < array_size - 1; k++){
      printf("%-d ",numbers[k]);
    }
    printf("%-d\n",numbers[array_size - 1]);
  }
  
  return 0;
}

