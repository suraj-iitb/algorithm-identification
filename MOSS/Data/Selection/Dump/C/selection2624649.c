#include <stdio.h>
#include <stdlib.h>
 
int main(){
 
  int i, j, n, temp, A[1000], minj, count=0;
 
  scanf("%d",&n);
 
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
 
  for(i=0; i<n-1; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]){
    minj = j;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(A[i] != A[minj]){
      count++;
    }
  }
 
  for(i=0; i<n-1; i++){
    printf("%d ", A[i]);
  }
 
  printf("%d\n",A[i]);
  printf("%d\n",count); 
 
  return 0;
}
 
