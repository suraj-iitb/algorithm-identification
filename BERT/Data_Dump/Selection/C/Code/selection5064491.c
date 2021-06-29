#include<stdio.h>

void selectionsort(int);
int main(){
  int n;
  scanf("%d",&n);
  selectionsort(n);
  return 0;
}


void selectionsort(int array_size){
  int i,j,array[array_size],temp,count,min,f;
  count = 0;
  for(i = 0;i < array_size;i++){
    scanf("%d",&array[i]);
  }
    for(i = 0;i < array_size - 1; i++){
       f = 0;
       min = i;
    for(j = i+1;j < array_size;j++){
      if(array[min] > array[j]){
    min = j;
    f = 1;
      }
    }
    if(f == 1){
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    count++;
    }
    }
     for(i = 0;i < array_size-1;i++){
       printf("%d ",array[i]);
  }
      printf("%d",array[i]);
      printf("\n%d\n",count);
}

