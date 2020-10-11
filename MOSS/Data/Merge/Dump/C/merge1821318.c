#include <stdio.h>

#define INFTY 2000000000;
#define MAX 500000

int count=0;
int S[MAX], L[MAX], R[MAX];

void merge(int *, int, int, int, int);
void mergeSort(int *, int, int, int);

int main()
{
  int i, n;

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ) scanf("%d", &S[i]);

  mergeSort(S, n, 0, n);

  for( i = 0 ; i < n ; i++ ){
    if( i >= 1 ) printf(" ");
    printf("%d", S[i]);
  }
  printf("\n");

  printf("%d\n", count);

  return 0;
}

void merge(int S[], int n, int left, int mid, int right)
{
  int n1, n2, i, j, k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  for( i = 0 ; i < n1 ; i++ ) L[i] = S[left+i];
  for( i = 0 ; i < n2 ; i++ ) R[i] = S[mid+i];

  L[n1] = R[n2] = INFTY;

  i = j = 0;
  
  for( k = left ; k < right ; k++ ){
    count++;
    if( L[i] <= R[j] ){
      S[k] = L[i];
      i++;
    }
    else {
      S[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int S[], int n, int left, int right)
{
  int mid;

  if( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(S, n, left, mid);
    mergeSort(S, n, mid, right);
    merge(S, n, left, mid, right);
  }
}
