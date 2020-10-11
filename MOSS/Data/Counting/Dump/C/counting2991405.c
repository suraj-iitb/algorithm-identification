#include <stdio.h>
//#include <stdlib.h>
#define N 10000
/*
int C[N],n;

int CountingSort(int A[],int B[],int k){
  int i;
  for(i=0; i<=N; i++){
    C[i]=0;
  }

  for(i=1; i<=n; i++){
    C[A[i]]++;
  }

  for(i=1; i<=N; i++){
    C[i]+=C[i-1];
  }

  for(i=1; i<=n; i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  return 0;
}
*/

int main(){
  int i,n,C[N];

  for(i=0; i<=N; i++){
    C[i]=0;
  }

  scanf("%d",&n);
  int A[n+1],B[n+1];
  for(i=0; i<n; i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  /*for(i=0; i<n; i++){
    B[i]=CountingSort(A,0,n);
  }
  */

  for(i=1; i<=N; i++){
    C[i]+=C[i-1];
  }

  for(i=1; i<=n; i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i=1; i<=n; i++){
  printf("%d",B[i]);
  if(i!=n) printf(" ");
  }
  printf("\n");

  return 0;

}

