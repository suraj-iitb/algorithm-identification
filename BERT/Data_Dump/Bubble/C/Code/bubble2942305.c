#include<stdio.h>

int main(){
  int i, j, n, tmp, flug=1, cnt=0;
  int A[100];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  while(flug){
    flug = 0;
    for(j=n-1; j>0; j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	cnt++;
	flug = 1;
      }
    }
  }
  
  for(i=0; i<n-1; i++){
    printf("%d ", A[i]);
  } printf("%d\n", A[i]);
  printf("%d\n", cnt);
  return 0;
}
