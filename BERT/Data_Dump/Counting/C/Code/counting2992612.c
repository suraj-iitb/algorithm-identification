#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
int C[VMAX+1];
int B[MAX];
void CountingSort(int A[],int n)
{
  int i,j;
    for(i=0; i<=VMAX+1; i++){
      C[i] = 0;
    }
    for(j=1; j<=n; j++){
      C[A[j]]++;
    }
    for(i=1; i<=VMAX+1; i++){
      C[i] = C[i]+C[i-1];
    }
    for(j=n; j>=1; j--){
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
    for(i=1; i<n; i++){
      printf("%d ",B[i]);
    }
    printf("%d\n",B[n]);
}
int main(){
  int A[MAX],n;  
  int i, j;

  scanf("%d", &n);
 
  for(i=1; i<=n; i++){
    scanf("%d",&A[i]);
  }
  CountingSort(A, n);
  
  return 0;
}

