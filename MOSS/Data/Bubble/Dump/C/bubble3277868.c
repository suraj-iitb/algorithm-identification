//バブルソート
//2018-12-07
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(){
  int count;
  int n, i;
  int array[N];
  int mark;
  int temp;

  scanf("%d",&n);

  if( n>100 || n<1){
    printf("要素数が範囲外です。\n");
    exit(1);
  }

  for( i=0 ; i<n ; i++ ){
    scanf("%d", &array[i]);
  }
  count=0;
  mark=1;
  while(mark){
    mark=0;
    for( i=n-1 ; i>=1 ; i-- ){
      if(array[i]<array[i-1]){
	temp=array[i];
	array[i]=array[i-1];
	array[i-1]=temp;
	count++;
	mark=1;

      }
      
    }
  }
  
  for( i=0 ; i<n ; i++ ){
    printf("%d",array[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);

  return 0;
}

