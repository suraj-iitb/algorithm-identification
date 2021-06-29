#include<stdio.h>
#define N 100
main(){
  int i, j, k, l, m = 0, A[N];
  scanf("%d", &k);
  for(i = 0;i < k;i++){
    scanf("%d", &A[i]);
  }
  for(i = 0;i < k;i++){
    for(j = k-1;j > i;j--){
      if(A[j] < A[j-1]){
	l = A[j];
	A[j] = A[j-1];
	A[j-1] = l;
	m++;
      }
    }
  }
  for(i = 0;i < k-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n", A[k-1], m);
  return 0;
}
