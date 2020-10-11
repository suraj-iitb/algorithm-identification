#include <stdio.h>
int main(){
  int i,j,N,k,key,A[100];
  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < N; i++){
    key =  A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
    for(k = 0; k < N-1; k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[k]);
  }
  return 0;
}
