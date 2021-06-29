#include<stdio.h>

#define N 100

int main(){
  int i, j, minj, A[N], n, a, cnt=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    if(i != minj) cnt++;
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[i],cnt);


  return 0;
}
