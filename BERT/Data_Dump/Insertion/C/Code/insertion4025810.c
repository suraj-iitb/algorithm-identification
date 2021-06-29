#include <stdio.h>
#define N 100

int main(){
  int arry[N];
  int key,i,j,k,in;
  
  scanf("%d",&in);
  
  for(i = 0; i < in; i++){
    scanf("%d",&arry[i]);
  }

  for(k = 0; k < in; k++){
    if(k > 0) printf(" ");
    printf("%d", arry[k]);
  }
  printf("\n");
  
  for(i = 1; i < in; i++){
    key = arry[i];
    j = i -1;
    
    while(j >= 0 && arry[j] > key){
      arry[j+1] = arry[j];
      j--;
    }
    arry[j+1] = key;

    for(k = 0; k < in; k++){
      if(k > 0) printf(" ");
      printf("%d", arry[k]);
    }
    printf("\n");
  }
  
  return 0;
}

