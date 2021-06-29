#include <stdio.h>
#define N 100

int main(){

  int temp;
  int n;
  int i, j;
  int A[N];
  int count;

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);    
  }
  
 count=0; 
  /* bubble_sort */
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(A[j-1] > A[j]){ /* 前の要素の方が大きかったら交換 */
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
      }
    }
  }
  
  for(i=0; i<n; i++){
    if(i == n - 1) printf("%d", A[i]);
    else printf("%d ", A[i]);
  }
  
  printf("\n");
  printf("%d", count);
  printf("\n");
  
  return 0;
}

