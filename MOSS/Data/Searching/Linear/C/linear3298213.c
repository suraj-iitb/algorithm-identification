#include <stdio.h>
#define NOT_FOUND -1

int array1[10000],array2[500],num1;

int linear_search(int);


int main(){  //線型探索

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
    if(linear_search(array2[i])==NOT_FOUND);
    else count++;
  }
  
    printf("%d\n",count);
  
  return 0;
}

int linear_search(int key){

  int i=0;
  array1[num1]=key;
  while(array1[i]!=key){
    i++;
  }
  if(i==num1){
    return -1;
  }
  return i;
}

