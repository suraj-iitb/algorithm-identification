#include <stdio.h>

int main(){
  int i, j, minj, n, buffer, count = 0, array[100];
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j<n; j++){
      if(array[j] < array[minj]){
        minj = j;
      }
    }
    if(array[i] != array[minj]){
     count++;
    }
    buffer = array[i];
    array[i] = array[minj];
    array[minj] = buffer;
  }
  
  for(i = 0; i < n; i++){
    printf("%d", array[i]);
    if(i < n-1){
      printf(" ");
    }
    else{
      printf("\n");
    }
  }
  printf("%d\n", count);
  
  return 0;
}

