#include<stdio.h>
#define N 100

int main(){
  int n,i,j,minj,via,count = 0,A[N];

  scanf("%d",&n);

  for(i = 0;i < n;i++) scanf("%d",&A[i]);

  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(A[i] != A[minj]) count++;
    via = A[i];
    A[i]  = A[minj];
    A[minj] = via;
  }
  for(i = 0;i < n;i++){
    printf("%d",A[i]);
    if(i == n-1) break;
    printf(" ");
  } printf("\n");
  printf("%d\n",count);
  return 0;
}

