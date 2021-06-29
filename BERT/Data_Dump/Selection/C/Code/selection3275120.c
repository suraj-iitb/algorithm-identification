#include<stdio.h>

int main(){
  int n, i, minj, flag, c = 0, t, j;
  scanf("%d",&n);
  int A[n];
  for(i = 0 ; i < n ; i++){
    scanf("%d", &A[i]);
  }
  for(i = 0 ; i < n ; i++){
    minj = i;
    flag = 0;
    for(j = i ; j < n ; j++){
      if(A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
    if(flag == 1) c++;
  }
  for(i = 0 ; i < n ; i++){
    if(i != n - 1) printf("%d ", A[i]);
    else printf("%d\n", A[i]);
  }
  printf("%d\n", c);
}

