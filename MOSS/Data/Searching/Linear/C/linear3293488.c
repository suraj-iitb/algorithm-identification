#include <stdio.h>
#include <stdlib.h>

int main(){
  int *array, i, j, n1, n2, key, count = 0;
  
  scanf("%d",&n1);
  array = malloc((n1 + 1) * sizeof(int));
  
  for(i = 0; i < n1; i++){
    scanf("%d",&array[i]); 
  }
  scanf("%d",&n2);
  for(i = 0; i < n2; i++){
    scanf("%d",&key);
    array[n1] = key;
    j = 0;
    while(array[j] != key){
      j++;
    }
    if(j == n1){
	
    }
    else{
      count++;
    }
  }
  printf("%d\n",count);
  
  return 0;
}

