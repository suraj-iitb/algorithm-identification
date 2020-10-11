#include <stdio.h>
#include <stdlib.h>

int count = 0;

static void merge_sort(int* array, int size);
static void merge_sort_rec(int* array, int begin, int end, int* work);
static void merge(int* array, int begin, int end, int mid, int* work);
static void print_array(const int* array, int size);

int main(void)
{
  int i;
  int n;
  int array[500000];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &array[i]);
  
  merge_sort( array, n);
  print_array( array, n);
  printf("%d\n", count);

  return 0;
}

void merge_sort(int* array, int size){

  int* work;
  work = malloc( sizeof(int) * size );
  merge_sort_rec( array, 0, size - 1, work );
  free( work );
  
}

void merge_sort_rec(int* array, int begin, int end, int* work){

  int mid;
  
  if( end <= begin ){
    return;
  }
	
  mid = (begin + end) / 2;
  merge_sort_rec( array, begin, mid, work );
  merge_sort_rec( array, mid + 1, end, work );

  merge( array, begin, end, mid, work );
}

void merge(int* array, int begin, int end, int mid, int* work){

  int i, j, k;

  for( i = begin; i <= mid; ++i){
    work[i] = array[i];
  }

  for( i = mid + 1, j = end; i <= end; ++i, --j){
    work[i] = array[j];
  }

  i = begin;
  j = end;
	
  for( k = begin; k <= end; ++k) {
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

void print_array(const int* array, int  size){
  size_t i;

  for( i = 0; i < size; ++i ){
    if(i == size-1) printf( "%d", array[i] );
    else printf("%d ", array[i]);
  }
  printf( "\n" );
}

