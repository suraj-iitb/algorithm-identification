#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void countingSort(int *,int *,int *,int,int);

int main(){
  int *A, *B;
  int C[VMAX+1];
  int n, i, j,k;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  /* your code */

for(i=1;i<=n;i++)    scanf(" %d", &A[i]);

k=A[1];

for(i=2;i<=n;i++){
    if(k<A[i]) k=A[i];
}

countingSort(A,B,C,k,n);

for(i=1;i<n;i++)  printf("%d ",B[i]);
printf("%d\n",B[i]);

  return 0;
}

void countingSort(int *A,int *B,int *C,int k,int n){
    int i,j;

    for(i=0;i<VMAX+1;i++)    C[i]=0;

    for(j=1;j<=n;j++)    C[A[j]]++;    
    
    for(i=1;i<=k;i++)    C[i] = C[i]+C[i-1];
    
    for(j=n;j>=1;j--){
            B[C[A[j]]] = A[j];
            C[A[j]]--;
    }
}
