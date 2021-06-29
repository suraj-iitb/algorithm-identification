#include <stdio.h>

void merge( int A[], int left, int mid, int right );
void mergeSort( int A[], int left, int right );

int A[500000];
int count = 0;

int main()
{
  int n;
  int i;
  
  scanf("%d",&n);
  for( i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  mergeSort( A, 0, n);

  for( i = 0; i < n; i++){
    if(i > 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
  
}

void mergeSort( int A[], int left, int right )
{
  int mid;

  if( ( left + 1 ) < right ){
    mid = ( left + right )/2;
    mergeSort( A, left, mid);
    mergeSort( A, mid, right);
    merge( A, left, mid, right);

  }

}


void merge( int A[], int left, int mid, int right )
{
  int i,n1,n2;
  int j;
  int k;
  int L[mid-left],R[right-mid];

  n1 = mid - left;
  n2 = right - mid;

  for( i = 0; i < n1; i++){
    L[i] = A[left + i];  
  }
  
  for( i = 0; i < n2; i++){
    R[i] = A[mid + i];    
  }

  L[n1] = R[n2] = 1000000000;
  i = 0;
  j = 0;

  for( k = left; k < right; k++){

    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }    
    else{
      A[k] = R[j];
      j = j + 1;
    }
    count++;
  }
}



