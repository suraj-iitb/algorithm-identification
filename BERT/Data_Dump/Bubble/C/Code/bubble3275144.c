#include<stdio.h>

int main(){
  int n, i, j, flag = 1, t;
  scanf("%d",&n);
  int A[n];
  for(i = 0 ; i < n ; i++){
    scanf("%d", &A[i]);
  }
  i = 0;
  while(flag){
    flag = 0;
    for(j = n - 1 ; j > 0 ; j--){
      if(A[j] < A[j - 1]){
	t = A[j];
	A[j] = A[j - 1];
	A[j - 1] = t;
	flag = 1;
	i++;
      }
    }
  }
  for(j = 0 ; j < n ; j++){
    if(j != n - 1) printf("%d ", A[j]);
    else printf("%d\n", A[j]);
  }
  printf("%d\n", i);
}

