#include<stdio.h>
int main()
{
  int n, a[101] ;
  scanf("%d", &n) ;

  int i, j ;
  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &a[i]) ;
  }

  int tmp, cnt, min_i ;
  cnt = 0 ;
  for( i = 0 ; i < n-1 ; ++i ){  // i = 未ソート部分の先頭
    min_i = i ;
    for( j = i ; j < n ; ++j ){
      if( a[min_i] > a[j] ){
        min_i = j ;
      }
    }
    if( i != min_i){
      tmp      = a[min_i] ;
      a[min_i] = a[i] ;
      a[i]     = tmp ;
      cnt++ ;
    }
  }

  for( i = 0 ; i < n-1 ; i++ ){
    printf("%d ", a[i]) ;
  }
  printf("%d\n%d\n", a[n-1], cnt) ;

  return 0 ;
}
