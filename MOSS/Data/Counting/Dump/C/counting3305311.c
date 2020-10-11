#include <stdio.h>

#define MAX 2000001
#define VMAX 10000


int main(){
  unsigned short A[MAX],B[MAX];
  int C[VMAX+1];
  int n, i, j;
  unsigned short k;

  scanf("%d", &n);
  
 
  for(i=1; i<=n; i++){
    scanf("%hd",&A[i]);
    if(k < A[i]) k = A[i];
  }
  k++;
  for(i=0; i<=k; i++){
    C[i] = 0;
  }

  for(j=1; j<=n; j++){
    C[A[j]]++;
  }

  for(i=1; i<=k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
  for(i=1; i<=n; i++){
    printf("%d",B[i]);
    if(i == n) break;
    printf(" ");
  }
  printf("\n");
 
  return 0;
  
}

