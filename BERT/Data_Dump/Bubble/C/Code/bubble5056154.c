#include <stdio.h>
#include <stdlib.h>

int main(){
  int n=100,i,j,v, count = 0,A[n];

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

  for(i = 0; i<n; i++){
    for(j = n-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
        v = A[j];
        A[j] = A[j-1];
        A[j-1] = v;
        count++;
      }
    }
  }

  for(i = 0; i<n; i++){
    printf("%d",A[i]);
    if(i < n-1)printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
