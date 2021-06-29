#include <stdio.h>
int main(){
  int i, j, k=0, flag,n,A[100],t;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  while(flag){
    flag = 0;
    for(j=n-1; j>=1; j--){
      if(A[j]<A[j-1]){
        t = A[j-1];
        A[j-1] = A[j];
        A[j] = t;
        flag = 1;
        k++;
      }
    }
  }
    for(i=0; i<n-1; i++){
      printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);
    printf("%d\n", k);
    return 0;

  }

