#include <stdio.h>
#include <stdlib.h>

int CountSort=0;

void swap(int *a,int *b){
  int tmp=*a;
  *a=*b; *b=tmp;
  CountSort++;
}

void BubbleSort(int a[],int num){
  int i,j;
  for(i=0;i<num;i++){
    for(j=num-1;j>i;j--){
      if(a[j]<a[j-1])swap(&a[j],&a[j-1]);
    }
  }
}

int main(void){
  int num,i;
  scanf("%d",&num);
  int array[200000];

  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }

  BubbleSort(array,num);

  for(i=0;i<num-1;i++)printf("%d ",array[i]);
  printf("%d\n%d\n",array[i],CountSort);


  return 0;
}
