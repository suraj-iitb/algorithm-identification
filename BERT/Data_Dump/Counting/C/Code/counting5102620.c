#include <stdio.h>
#include <stdlib.h>

void countingsort(int *, int*, int);

int n;

int main(){
  int i, j;
  int *A, *B, max=0;
  A=(int*)malloc(2000000*sizeof(int));
  B=(int*)malloc(2000000*sizeof(int));

  scanf("%d", &n);
  if(n<1 || n>2000000) exit(1);

  for(i=1; i<n+1; i++){
    scanf("%d", &A[i]);
    if(A[i]<0 || A[i]>10000) exit(2);
    if(max<A[i]) max=A[i];
  }

   countingsort(A, B, max);

  for(j=1; j<n+1; j++){
    if(j<n) printf("%d ", B[j]);
    else printf("%d\n", B[j]);
  }

  free(A);
  free(B);

  return 0;
}

void countingsort(int A[], int B[], int k){
  int i, j, C[k];

  for(i=0; i<=k; i++) C[i]=0;

  for(j=1; j<n+1; j++) C[A[j]]++;

  for(i=1; i<=k; i++) C[i]=C[i]+C[i-1];

  for(j=n; j>=1; j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
