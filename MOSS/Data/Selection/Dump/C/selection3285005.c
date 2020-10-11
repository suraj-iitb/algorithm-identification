//選択ソート
//2018-12-11
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N 100

int ss(int *, int);

int main(){
  int array[N];
  int i,count;
  int n;

  scanf("%d",&n);

  if( n<1 || n>N ){
    printf("要素数が適当ではありません。\n");
    exit(1);
  }

  for( i=0 ; i<n ; i++ ){
    scanf("%d",&array[i]);
  }

 
  count = ss(array,n);
    
  for( i=0 ; i<n ; i++ ){
    printf("%d",array[i]);

    if( i<n-1 )printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

int ss( int array[], int n){
  int i, j, temp;
  int count=0;
  int min;

  for( i=0 ; i<n ; i++ ){
    min=i;
    for( j=i ; j<n ; j++ ){
      if( array[j] < array[min] ){
	min = j;
      }
    }
    temp = array[i];
    array[i] = array[min];
    array[min] = temp;

    if( i!=min ){
      count = count + 1;
    }
  }
  return count;
}

