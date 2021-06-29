#include <stdio.h>

void dP(int* A, int N){
  int n;
  for (n=0;n<(N-1);n++)
    printf("%d ",A[n]);
  printf("%d\n",A[N-1]);
}

void s(int* A, int N){
  int i;
  for (i=1;i<N;i++) {
    int k=A[i];
    int j=i-1;
    dP(A,N);
    while((j>=0)&&(A[j]>k)) {
      A[j+1]=A[j];
      j--;
      A[j+1]=k;
    }
  }
}

int main(void) {
  int I[100],N,n;
  scanf("%d\n",&N);
  for(n=0;n<N;n++)
    scanf("%d",&I[n]);
  s(I,N);
  dP(I,N);
  return 0;
}
