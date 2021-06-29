#include <stdio.h>

#define N 100

int main(){
  int i, j, k, max, key;
  int array[N];
  
  scanf("%d", &max); /* 数列の長さ */
  for(i = 0; i < max; i++)scanf("%d", &array[i]);
  
  /* 挿入ソート */
  for(i = 1; i < max; i++){
  /* 表示 */
    for(k = 0; k < max; k++){
      printf("%d", array[k]);
      if(k < max-1)printf(" ");
      else printf("\n");
    }
    
    key = array[i];
    j = i - 1; 
    while(j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
  /* 表示 */
    for(k = 0; k < max; k++){
      printf("%d", array[k]);
      if(k < max-1)printf(" ");
      else printf("\n");
    }
  return 0;
}

