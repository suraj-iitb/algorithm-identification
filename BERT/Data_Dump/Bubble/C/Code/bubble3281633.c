#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, j, temp, count = 0, n, *array;
  
  scanf("%d",&n);
  array = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d",&array[i]);
  }
  for(i = 0; i < n - 1; i++){
    for(j = n - 1; j > i; j--){
      if(array[j - 1] > array[j]){
	temp = array[j - 1];
	array[j - 1] = array[j];
	array[j] = temp;
	count++;
      }
    }
  }
  for(i = 0; i < n - 1; i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[n - 1]);
  printf("%d\n",count);
  
  return 0;
}

