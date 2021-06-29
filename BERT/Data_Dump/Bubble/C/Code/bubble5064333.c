#include<stdio.h>
#define N 100
void bubblesort(int);
int main(){
  int n;
  scanf("%d",&n);
  bubblesort(n);
  return 0;
}


void bubblesort(int array_size){
  int i,j,array[array_size],temp,count;
  count =0;
  for(i = 0;i < array_size;i++){
    scanf("%d",&array[i]);
}
  for(i = 0;i < (array_size - 1); i++){
    for(j = (array_size - 1);j>i;j--){
      if(array[j] < array[j-1]){
	temp = array[j-1];
	array[j-1] = array[j];
	array[j] = temp;
	count++;
      }
    }
  }
  for(i = 0;i <array_size - 1;i++){
    printf("%d ",array[i]);
      }
   printf("%d",array[i]);
  printf("\n%d\n",count);
}

