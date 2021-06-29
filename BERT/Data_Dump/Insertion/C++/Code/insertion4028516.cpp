#include<stdio.h>

#define N 100
#define A 1000

int main(){
  int array[A];
  int value,num,i,j,k;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<num;i++){
    
    value = array[i];

    j = i-1;

    while(j >= 0 && array[j] >  value){
      array[j+1] = array[j];
      j--;
      array[j+1] = value;
    }
    
    for(k=0;k<num-1;k++){
      printf("%d ",array[k]);    
    }

    printf("%d",array[k]);   
    printf("\n");
      
  }

  return 0;
}

    

