#include <stdio.h>
#define NOT_FOUND -1
int array1[100000],array2[50000],num1;
int binary_search(int);

int main(){

  int i,num2,count=0;
  
  scanf("%d",&num1);

  for(i=0;i<num1;i++){
    scanf("%d",&array1[i]);
  }
  
  scanf("%d",&num2);

  for(i=0;i<num2;i++){
    scanf("%d",&array2[i]);
  }
   for(i=0;i<num2;i++){
    if(binary_search(array2[i])==NOT_FOUND);
    else count++;
  }
  
    printf("%d\n",count);
  
  return 0;
}

int binary_search(int key){

  int left=0;
  int right=num1;
  while(left<right){
   int  mid=(left+right)/2;
    if(array1[mid]==key){
      return mid;
    }
    else if(key<array1[mid]){
      right=mid;
    }
      else{
	left = mid +1;
      }
  }
      return NOT_FOUND;
}

