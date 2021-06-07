#include <stdio.h>

int linearsearch(int *,int,int);

int main(){
  int i,num1,num2,array[10001],key,count=0;
  scanf("%d",&num1);
  for(i=0;i<num1;i++) scanf("%d",&array[i]);

  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&key);
    if(linearsearch(array,num1,key)==1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int linearsearch(int *array,int num1,int key){
  int i=0;
  array[num1]=key;
  while(array[i]!=key) i++;
  if(i!=num1) return 1;
  else return 0;
}

