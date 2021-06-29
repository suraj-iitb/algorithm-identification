#include<stdio.h>
#include<stdlib.h>

int main() {
  int i=0, j=0, printi=0, l=0, key=0;
  int array[100];

  scanf("%d", &l);
  for(i=0 ; i<l ; i++) {
    scanf("%d", &array[i]);
  }
  
  for(printi = 0 ; printi < l; printi++){
    printf("%d", array[printi]);
    if(printi != l-1) printf(" ");
  }
  printf("\n");
    
  for(j=1 ; j<l ; j++){
    key = array[j];

    i = j-1;
    while((i >= 0) && (array[i] > key)){
      array[i+1] = array[i];
      i--;
    }
    
    array[i+1] = key;

    for(printi = 0 ; printi < l; printi++){
      printf("%d", array[printi]);
      if(printi != l-1) printf(" ");
    }
    printf("\n");
  }
  
  return 0;
}

