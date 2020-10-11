#include <stdio.h>

#define N 2000001
#define E 10000

int A[N],B[N],C[N],n;

void CountingSort(int);
void Print(int *);

main(){
  
  int i,k=0;
  n=0;
  
  scanf("%d",&n);
  
  if(N < n || n < 0) return 0;
  
  for(i=1;i <= n;i++){
    scanf("%d",&A[i]);
    
    if(E < A[i]|| A[i] < 0) return 0;
    
    if(k < A[i]) k=A[i]+1;
  }
  
  CountingSort(k);
  
  Print(B);
  
  return 0;
}

void CountingSort(int k){
  int i,j;
  
  for(i = 0;i <= k;i++) C[i] = 0;
  
  for(j = 1;j <= n;j++) C[A[j]]++;
  
  for(i = 1;i <= k;i++) C[i] = C[i]+C[i-1];
  
  for(j = n; j > 0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

void Print(int *B){
  int i;
  
  for(i=1;i <= n;i++){
    if(i == n) printf("%d",B[i]);
    else printf("%d ",B[i]);
  }
  printf("\n");
}
