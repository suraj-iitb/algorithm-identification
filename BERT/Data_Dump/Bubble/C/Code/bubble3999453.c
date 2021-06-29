#include<stdio.h>
int main()
{
  int n, a[101] ;
  scanf("%d", &n) ;

  int i, j ;
  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &a[i]) ;
  }

  int tmp, cnt ;
  cnt = 0 ;
  for( j = 1 ; j < n ; ++j ){
    for( i = n-1 ; i >= j ; i-- ){
      //tmp = a[i] ;
      if( a[i-1] > a[i] ){
        tmp = a[i] ;
        a[i] = a[i-1] ;
        a[i-1] = tmp ;
        cnt += 1 ;
      }
    }
  }

  for( i = 0 ; i < n-1 ; i++ ){
    printf("%d ", a[i]) ;
  }
  printf("%d\n%d\n", a[n-1], cnt) ;
  return 0 ;
}
