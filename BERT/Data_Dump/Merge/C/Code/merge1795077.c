#include <stdio.h>

#define MAX 1000000
#define INF 2000000000

void merge(int[],int,int,int);
void mergeSort(int[],int,int);

int count=0;

int main()
{
  int i, n, array[MAX];
  int left, right;

  scanf("%d", &n);

  for( i=0; i<n; i++){
    scanf("%d", &array[i]);
  }

  left = 0;
  right = n;

  mergeSort( array, left, right);

  for( i=0; i<n-1; i++){
    printf("%d ", array[i]);
  }

  printf("%d\n%d\n", array[i], count);

  return 0;
}

void mergeSort( int A[], int left, int right){
  int mid;

  if( left + 1 < right ){
    mid = ( left + right ) / 2;
    mergeSort( A, left, mid);
    mergeSort( A, mid, right);
    merge( A, left, mid, right);
  }
  
}

void merge( int A[], int left, int mid, int right){
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  int l_array[n1+1], r_array[n2+1];


  for( i=0; i<n1; i++){
    l_array[i] = A[left+i];
  }

  for( i=0; i<n2; i++){
    r_array[i] = A[mid+i];

  }

  l_array[n1] = INF;
  r_array[n2] = INF;

  i = 0;
  j = 0;

  for( k=left; k<right; k++){
    if( l_array[i] <= r_array[j] ){
      A[k] = l_array[i];
      i++;
    }
    else{
      A[k] = r_array[j];
      j++;
    }    
    count++;
  }

}
