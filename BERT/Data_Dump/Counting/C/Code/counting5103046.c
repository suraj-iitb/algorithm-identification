#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(short *,short *,int,int);
int main(){
  short A[MAX], B[MAX];
  int C[VMAX+1];
  int n,i,j,k=-1;

  scanf("%d", &n);

  for(i=1;i<=n;i++){
    scanf("%hd",&A[i]);
    if(k<A[i]) k=A[i];
  }

  CountingSort(A,B,k,n);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i==n) break;
    else printf(" ");
  }

  printf("\n");

  return 0;
}

void CountingSort(short A[],short B[],int k,int n){
  int C[k+1],i,j;
  for(i=0;i<=k;i++)
    C[i] = 0;
  for (j = 1;j<=n;j++){
    C[A[j]]++;
  }
  for (i = 1 ;i<= k;i++){
    C[i] = C[i] + C[i-1];
  }
  for (j = n ;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
