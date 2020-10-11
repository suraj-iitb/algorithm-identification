#include<stdio.h>

int main(){
  int i, j, n, minJ, tmp, cnt=0;
  int A[100];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  for(i=0; i<n; i++){
    minJ = i;
    for(j=i+1; j<n; j++){
      if(A[j] < A[minJ]){
	minJ = j;
      }
    }
    if(minJ != i){
      tmp = A[i];
      A[i] = A[minJ];
      A[minJ] = tmp;
      cnt++;
    }
  }

  for(i=0; i<n-1; i++){
    printf("%d ", A[i]);
  } printf("%d\n", A[i]);
  printf("%d\n", cnt);
}

