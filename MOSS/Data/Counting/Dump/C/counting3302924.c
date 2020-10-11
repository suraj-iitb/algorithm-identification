#include <stdio.h>
#define MAX 2000001
#define VMAX 10001

int main() {

  int i,n,k=0,A[MAX];
  int j,C[MAX],B[MAX];
  
  scanf("%d",&n);
  for(i = 1; i < n + 1; i++) {
    scanf("%d",&A[i]);
 
    if(A[i] > k) {
      k = A[i];
    }
  }
    
 for(i = 0; i <= k; i++) {
    C[i] = 0;
 }

  for(j = 1; j <= n; j++) {
    C[A[j]]++;
  }

  for(i = 1; i <= k; i++) {
    C[i] = C[i] + C[i-1];
  }
 
  for(j = n; j >= 1; j--) {
    B[C[A[j]]] = A[j];  
    C[A[j]]--;
  }

  
  for(i = 1; i < n + 1; i++) {
    printf("%d",B[i]);
    if(i < n) printf(" ");
    else printf("\n");
  }
  

  return 0;
}




