#include <stdio.h>

int main(void){
  int i,j,n,temp,mini;
  int cnt = 0;
  int array[100];

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ) scanf("%d",&array[i]);

  for( i = 0 ; i < n ; i++ ){
    mini = i;
    for( j = i ; j < n ; j++ ){
      if( array[j] < array[mini] ) mini = j;
    }
    temp = array[i];
    array[i] = array[mini];
    array[mini] = temp;
    if( i != mini ) cnt++;
  }
  for( i = 0 ; i < n ; i++ ){
    if( i < n - 1 ) printf("%d ",array[i]);
    else printf("%d\n",array[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
