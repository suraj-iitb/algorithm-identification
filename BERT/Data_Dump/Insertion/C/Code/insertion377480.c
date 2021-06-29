#include <stdio.h>

int main(void){
  int i,j,k,n,temp;
  int array[100];

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&array[i]);
  }

  for( i = 0 ; i < n - 1 ; i++){
    printf("%d ",array[i]);
  }

  printf("%d\n",array[i]);

  for( j = 1 ; j < n ; j++ ){
    temp = array[j];
    i = j - 1;
    while( i >= 0 && array[i] > temp ){
      array[i+1] = array[i];
      i = i - 1;
    }
    array[i+1] = temp;

    for( k = 0 ; k < n - 1 ; k++ ){
      printf("%d ",array[k]);
    }
    printf("%d\n",array[k]);
  }
  return 0;
}
