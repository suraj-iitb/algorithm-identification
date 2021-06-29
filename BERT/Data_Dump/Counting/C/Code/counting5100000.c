#include <stdio.h>
#define C_MAX 10000

int n;

void countingsort(int *A,int *B,int k){
  int i,j,c[C_MAX+1];
  for(i=0; i<=C_MAX; i++) c[i] = 0;
  for(j=0; j<n; j++) c[A[j]]++;
  for(i=1; i<=C_MAX; i++) c[i] = c[i] + c[i-1];
  for(j=n-1; j>=0; j--){

    B[c[A[j]]] = A[j];
    c[A[j]] --;
  }

}

int main () {

  int i,k;
  k = 0;

  scanf("%d",&n);
  int A[n],B[n];
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(k < A[i]) k=A[i];
    B[i] = 0;
  }

  countingsort(A,B,k);

  for(i=1; i<n; i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);

  return 0;

}
