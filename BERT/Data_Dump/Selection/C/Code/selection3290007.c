#include <stdio.h>

int main(){
  int i,j,minj,cp,ct=0,n,A[100];
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(minj != i){
      cp = A[i];
      A[i] = A[minj];
      A[minj] = cp;
      ct++;
    }
  }
  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],ct);


  return 0;
}
