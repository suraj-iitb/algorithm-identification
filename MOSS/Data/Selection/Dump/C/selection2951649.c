#include<stdio.h>
int main(){
  int i,j,minj,n,tmp,A[100],count = 0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0 ; i < n ; i++){
    minj = i;
    for(j = i ; j < n ; j++){
      if(A[j] < A[minj]) {
	minj = j;
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(i != minj)count++;
  }
  for(i = 0 ; i < n ; i++){
    if(i == n - 1)printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

