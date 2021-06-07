#include <stdio.h>
#include <stdlib.h>

int binarySearch(int, int);

int *array;

int main(){
  int i, j, key, n1, n2, sum = 0;

  scanf("%d",&n1);
  array = malloc((n1 + 1)* sizeof(int));
  for(i = 0; i < n1; i++){
    scanf("%d",&array[i]);    
  }
  scanf("%d",&n2);
  for(i = 0; i < n2; i++){
    scanf("%d",&key);
    if(binarySearch(key, n1)){
      sum++;
    } 
  }
  printf("%d\n",sum);
  
  return 0;
}

int binarySearch(int key, int n1){
  int left = 0;
  int right = n1;
  int mid;

  while(left < right){
    mid = (left + right) / 2;
    if(key == array[mid]){
      return 1;
    }
    if(key > array[mid]){
      left = mid + 1;
    }
    else if(key < array[mid]){
      right = mid;
    }
  }
  return 0;
}

