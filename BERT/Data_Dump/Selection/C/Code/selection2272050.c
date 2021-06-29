#include <stdio.h>
#define N 100

int main(){
  int n, i, j, minj, temp, count=0;
  int A[N+1];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
  }
  
  for(i =0; i<n-1;i++) {
    minj = i;
    for(j=i;j<n;j++) {
      if(A[j] < A[minj]) minj =j;
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(i != minj) count++;
  }
  
  for(i=0;i<n;i++) {
    if(i < n-1) printf("%d ",A[i]);
    else if(i == n-1) printf("%d\n", A[n-1]);
  }
  printf("%d\n", count);
  return 0;
}
