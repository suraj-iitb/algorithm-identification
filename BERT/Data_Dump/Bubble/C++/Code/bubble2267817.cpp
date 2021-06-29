#include <stdio.h>

int main(){

  int n,i,sum = 0,j,temp;
  int array[124] = {};

  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&array[i]);
  }
  
  for(i = 0;i < n;i++){
    for(j = n - 1; j > i ;j--){
      if(array[j - 1] > array[j]){
	temp = array[j];
	array[j] = array[j - 1];
	array[j - 1] = temp;
	sum += 1;
      }
    }
  }

  for(i = 0;i < n;i++){
    if(i != n - 1) printf("%d ",array[i]);
    else printf("%d",array[i]);
  }
  printf("\n");
  printf("%d\n",sum);

  return 0;
}
