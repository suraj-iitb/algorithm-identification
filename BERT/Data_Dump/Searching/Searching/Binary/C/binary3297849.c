//二分探索
//2018-12-17
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N1 100000
#define N2 50000

int Search( int *, int ,int );

int main (){
  int array1[N1];
  int array2[N2];
  int answer = 0;
  int n1, n2;
  int i;
  int re;
    
  scanf( "%d", &n1 );
  if( n1 > 100000 || n1 < 1 ){
    printf("要素数が適当でありません。\n");
    exit(1);
  }
  for( i = 0 ; i < n1 ; i++ ){
    scanf( "%d", &array1[i] );
  }

  scanf( "%d", &n2 );
  if( n2 > 50000 || n2 < 1 ){
    printf("要素数が適当でありません。\n");
    exit(2);
  }
  
  for( i = 0 ; i < n2 ; i++ ){
    scanf( "%d", &array2[i] );
  }
  
  for( i = 0 ; i < n2 ; i++ ){
    re = Search( array1, array2[i], n1 );
    if( re != -1 ){
      answer++;
    }
  }

  printf("%d\n", answer);

  return 0;
}

int Search( int *Array, int y, int n ){
  int left = 0;
  int right = n;
  int mid;

  while( left < right ){
    mid = ( left + right ) / 2;
    if( Array[mid] == y ){
      return mid;
    }
    else if( y > Array[mid] ){
      left = mid + 1;
    }
    else{
      right = mid;
    }
  }

  return -1;
}

  
    

