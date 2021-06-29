
#include <stdio.h>
#include <stdlib.h>

int count = 0;

static void mergeSort(int* array, int size);
static void mergeSort_rec(int* array, int left, int right, int* work);
static void merge(int* array, int left, int right, int mid, int* work);
static void print(const int* array, int size);


void mergeSort(int* array, int size){

  int* work;
  work = malloc( sizeof(int) * size );
  mergeSort_rec( array, 0, size - 1, work );
  free( work );
  
}

void mergeSort_rec(int* array, int left, int right, int* work){

  int mid;
  
  if( right <= left ){
    return;
  }
        
  mid = (left + right) / 2;
  mergeSort_rec( array, left, mid, work );
  mergeSort_rec( array, mid + 1, right, work );

  merge( array, left, right, mid, work );
}

void merge(int* array, int left, int right, int mid, int* work){

  int i, j, k;

  for( i = left; i <= mid; ++i){
    work[i] = array[i];
  }

  for( i = mid + 1, j = right; i <= right; ++i, --j){
    work[i] = array[j];
  }

  i = left;
  j = right;
        
  for( k = left; k <= right; ++k) {
    if( work[i] <= work[j] ){
      array[k] = work[i];
      ++i;
    }
    else{
      array[k] = work[j];
      --j;
    }
    count++;
  }
}

void print(const int* array, int  size){
  size_t i;

  for( i = 0; i < size; ++i ){
    if(i == size-1) printf( "%d", array[i] );
    else printf("%d ", array[i]);
  }
  printf( "\n" );
}

int main(void)
{
  int i;
  int n;
  int array[500000];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &array[i]);
  
  mergeSort( array, n);
  print( array, n);
  printf("%d\n", count);

  return 0;
}

