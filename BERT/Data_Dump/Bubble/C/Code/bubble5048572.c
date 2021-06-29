#include<stdio.h>

int main(){

  int quantity,i,j,k,temp,count=0;

  scanf("%d",&quantity);

  int array[quantity];
  
  for(k = 0; k < quantity; k++){
    scanf("%d",&array[k]);
  }
  for(i = 0; i < quantity; i++){
    for(j = quantity-1; j >= i+1; j--){
      if(array[j] < array[j-1]){
	temp = array[j-1];
	array[j-1] = array[j];
	array[j] = temp;
	count++;
      }
    }
  }

  int l;
  for(l = 0; l < quantity-1; l++){
    printf("%d ",array[l]);
  }
    printf("%d",array[quantity-1]);
  
  printf("\n");
  printf("%d\n",count);

  return 0;
}

