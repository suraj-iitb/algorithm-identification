#include <stdio.h>

int main(void){
  int i,j,n,temp;
  int cnt = 0;
  int array[100];

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&array[i]);
  }

  for( i = 0 ; i < n - 1 ; i++ ){
    for( j = n - 1 ; j > i ; j-- ){
      if( array[j-1] > array[j] ){
        temp = array[j];
        array[j] = array[j-1];
        array[j-1] = temp;
        cnt++;
      }
    }
  }
  for( i = 0 ; i < n ; i++ ){
    if( i < n - 1 ) printf("%d ",array[i]);
    else printf("%d\n",array[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
