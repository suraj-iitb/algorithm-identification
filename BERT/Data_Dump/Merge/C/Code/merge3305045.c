//マージソート
//2018-12-21
//Ebitani Akira

#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define N2 1000000000

void Merge( int *, int, int, int );
void MergeSort( int *, int, int );

int count = 0;
int array[N];

int main (){
  int i, j, n;

  scanf( "%d", &n );
  for( i = 0 ; i < n ; i++ ){
    scanf( "%d", &array[i] );
  }

  MergeSort( array, 0, n );
  
  for( i = 0 ; i < n ; i++ ){
    printf( "%d", array[i] );
    if( i != n - 1 ){
      printf( " " );
    }
  }

  printf( "\n" );
  printf( "%d\n", count );

  return 0;
}
    
void MergeSort( int array[], int left, int right ){
  int mid;

  if( left + 1 < right ){

    mid = ( left + right ) / 2;
    MergeSort( array, left, mid );
    MergeSort( array, mid, right );
    Merge( array, left, mid, right );
  }
}

void Merge( int array[], int left,int mid, int right ){
  int n_left, n_right;
  n_left = mid - left;
  n_right = right - mid;

  int i = 0, j = 0, k;

  int Left[n_left];
  int Right[n_right];
  
 for( i = 0 ; i < n_left ; i++ ){
    Left[i] = array[left + i];
  }
  for( i = 0 ; i < n_right ; i++ ){
    Right[i] = array[mid + i];
  }

  Left[n_left] = N2;
  Right[n_right] = N2;
  
  for( i = 0, j = 0, k = left ; k < right ; k++ ){
    count = count + 1;

    if( Left[i] <= Right[j] ){
      array[k] = Left[i];
      i++;
    }
    else{
      array[k] = Right[j];
      j++;
    }
  }
}


