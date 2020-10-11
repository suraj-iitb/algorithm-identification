#include<stdio.h>

int main(){
  int i, j, minj, n, p, count=0;
  int A[100];

  scanf("%d",&n);

  for(i=0 ; i<n ; i++) scanf("%d",&A[i]);

  for(i=0 ; i<n-1 ; i++){
    minj = i;
    for(j=i+1 ; j<n ; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(minj != i){
      p = A[i];
      A[i] = A[minj];
      A[minj] = p;
      count++;
    }
  }
  
  for(i=0 ; i<n-1 ; i++) printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],count);
  
  return 0;
}
