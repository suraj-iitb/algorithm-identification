#include<stdio.h>
int main()
{
  int a[1001] ;
  int i, j, k ;
  int n ;
  scanf("%d",&n) ;

  // オリジナル配列入力
  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&a[i]) ;
  }

  int tmp ;
  for( i = 1 ; i < n ; i++ ){
    for( k = 0 ; k < n-1 ; k++ ){
      printf("%d ", a[k]) ;
    }
    printf("%d\n", a[k]) ;
    tmp = a[i] ;
    j = i - 1 ;
    while( 0 <= j && a[j] > tmp ){
      a[j+1] = a[j] ;
      j-- ;
    }
    a[j+1] = tmp ; // ここでi回目のソート完了
  }

  for( k = 0 ; k < n-1 ; k++ ){
    printf("%d ", a[k]) ;
  }
  printf("%d\n", a[k]) ;

  return 0 ;
}
