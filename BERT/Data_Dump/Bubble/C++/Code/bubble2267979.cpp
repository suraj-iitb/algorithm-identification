#include <stdio.h>
#define MAX 100

int main(){

  int num,i,j,array[MAX],tem,count=0;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<=num-1;i++){
    for(j=num-1;j>i;j--){
      if(array[j]<array[j-1]){
	tem = array[j];
	array[j] = array[j-1];
	array[j-1] = tem;
	count++;
      }
    }
  }
  for(i=0;i<num-1;i++){
    printf("%d ",array[i]);
      }
  printf("%d\n",array[num-1]);
      

      printf("%d\n",count);


}
