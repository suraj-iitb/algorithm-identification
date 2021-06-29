#include<stdio.h>

int main(){

  int quantity,i,j,k,l,min,min_element,temp,count=0;

  scanf("%d",&quantity);

  int array[quantity];

  for(l = 0; l < quantity; l++){
    scanf("%d",&array[l]);
  }

  for(i = 0; i < quantity-1; i++){
    min = array[i+1];
    min_element = i+1;
    for(j = i+1; j < quantity; j++){
      if(min > array[j]){
	min = array[j];
	min_element = j;
      }
    }
    if(array[i] > min){
      temp = array[i];
      array[i] = min;
      array[min_element] = temp;
      count++;
    }    
  }

for(k = 0; k < quantity-1; k++){
  printf("%d ",array[k]);
 }
printf("%d\n",array[quantity-1]);
printf("%d\n",count);

return 0;
}
    
    

