#include <stdio.h>
#define N 100

int main(){
  int n,i,j;
  int tmp,key;
  int A[N];
  
  scanf("%d",&n);
  for(i=0 ; i<n ; i++) scanf("%d",&A[i]);

  for(i=1 ; i<=n ; i++){
    for(j=0 ; j<n-1 ; j++){
      printf("%d ",A[j]);
    }
    printf("%d",A[n-1]);
    printf("\n");
    
    key = A[i];
    j = i - 1;
    while(j>=0 && key<A[j]){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
  }
  return 0;
}
