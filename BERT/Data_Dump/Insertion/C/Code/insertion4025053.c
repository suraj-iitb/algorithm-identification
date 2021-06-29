#include <stdio.h>

int main(){
  int n,i,j,key;
  scanf("%d",&n);
  int array[n];
  for(i = 0; i < n; i++){
    scanf("%d",&array[i]);
  }
  for(j = 0; j <= n - 1; j++){
    key = array[j];
    i = j - 1;
    while(i >= 0 && array[i] > key){
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = key;
    for(i = 0; i < n; i++){
      printf("%d",array[i]);
      if(i == n - 1){
        printf("\n");
        break;
      }
      printf(" ");
    }
  }
  return 0;
}

