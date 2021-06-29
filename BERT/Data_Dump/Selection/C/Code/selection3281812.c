#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, j, minj, n, temp, count = 0, flag = 0, *array;
  
  scanf("%d",&n);
  
  array = (int *)malloc(n * sizeof(int));
  
  for(i = 0; i < n; i++){
    scanf("%d",&array[i]);
  }
  
  for(i = 0; i < n  - 1; i++){
    minj = i;
    for(j = i + 1; j < n; j++){
      if(array[minj] > array[j]){
	minj = j;
	flag = 1; 
      }
    }
    if(flag == 1){
      temp = array[i];
      array[i] = array[minj];
      array[minj] = temp;
      count++;
    }
    flag = 0;
  }
  
  for(i = 0; i < n - 1; i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[n - 1]);
  
  printf("%d\n",count);
  
  return 0;
}
