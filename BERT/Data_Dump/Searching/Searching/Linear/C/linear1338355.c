#include<stdio.h>
#define S 10000
#define T 500

main(){

  int n[S],q[T],count=0,a,b,i,j;

  scanf("%d",&a);
  for( i = 0 ; i < a ; i++ )
    scanf("%d",&n[i]);

  scanf("%d",&b);
  for( i = 0 ; i < b ;i++ )
    scanf("%d",&q[i]);

  for( i = 0 ; i < b ; i++){
    for( j = 0 ; j < a ; j++ ){
      if( n[j] == q[i] ){
	count++;
	  break;
      }
    }
  }

  printf("%d\n",count);
  
  return 0;
}
