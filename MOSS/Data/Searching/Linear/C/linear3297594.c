//線形探索
//2018-12-17
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N1 10000
#define N2 500

int main (){
  int array1[N1];
  int array2[N2];
  int i, j, answer;
  int n1, n2;

  scanf( "%d", &n1 );
  if( n1 > 10000 || n1 < 1 ){
    printf("要素数が適当でありません。\n");
    exit(1);
  }
  for( i = 0 ; i < n1 ; i++ ){
    scanf( "%d", &array1[i] );
  }

  scanf( "%d", &n2 );
  if( n2 > 500 || n2 < 1 ){
    printf("要素数が適当でありません。\n");
    exit(2);
  }
  for( i = 0 ; i < n2 ; i++ ){
    scanf( "%d", &array2[i] );
  }

  answer = 0;
  
  for( i = 0 ; i < n2 ; i++ ){
    for( j = 0 ; j < n1 ; j++ ){
      if( array2[i] == array1[j] ){
	answer++;
	break;
      }
    }
  }

  printf("%d\n", answer);

  return 0;
}

