#include <stdio.h>
#include <stdlib.h>

int main(){
  int n=100,i,j,v, count = 0,minj,A[n];

  scanf("%d",&n);
  if(n<1 || n>100){
    printf("size error\n");
    exit(1);
  }

  for(i = 0;i<n;i++){
    scanf("%d", &A[i]);
    if(A[i]<0 || A[i]>100)
      exit(1);
  }

  for(i = 0; i<=n-2; i++){
    minj = i;
    for(j = i; j<=n-1; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    v = A[i];
    A[i] = A[minj];
    A[minj] = v;
    if(minj != i)count++;
  }

  for(i = 0; i<n; i++){
    printf("%d",A[i]);
    if(i < n-1)printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
