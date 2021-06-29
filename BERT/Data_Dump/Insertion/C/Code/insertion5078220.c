#include<stdio.h>

int main(){
  int i,j,k,l,m,quantity,key,array[100];

  scanf("%d",&quantity);
  for(i = 0; i < quantity; i++){
    scanf("%d",&array[i]);
  }

  for(j = 1; j <= quantity-1; j++){
    key =array[j];
    for(l = 0; l < quantity-1; l++){
      printf("%d ",array[l]);
    }
    printf("%d",array[quantity-1]);
    for(k = j - 1; k >= 0; k--){
      if(key < array[k]){
	array[k+1] = array[k];
	array[k] = key;
      }
    }
    printf("\n");
  }
  for(m = 0; m < quantity-1; m++){
    printf("%d ",array[m]);
  }
  printf("%d\n",array[quantity-1]);
 
  
  return 0;
}




	

