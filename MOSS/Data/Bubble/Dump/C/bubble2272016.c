#include <stdio.h>
#define N 100

int main(){
  int n, i, j, temp, count=0;
  int A[N+1];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
  }
  
  for(i = 0; i<n-1; i++) {
    for(j=n-1;j>0;j--) {
      if(A[j]< A[j -1]) {
        temp = A[j-1];
        A[j-1] = A[j];
        A[j] = temp;
        count++;
      }
    }
  }
  
  for(i=0;i<n;i++) {
    if(i < n-1) printf("%d ",A[i]);
    else if(i == n-1) printf("%d\n", A[n-1]);
  }
  printf("%d\n", count);
  return 0;
}
