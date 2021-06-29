#include <stdio.h>
#include <stdlib.h>

void counting(unsigned short *A,unsigned short*B,int n){
  int C[10001];
  int i;
  
  for (i=0;i<10001;i++){
    C[i] = 0;
  }
  for(i = 1; i <= n;i++){
    C[A[i]]++;
  }
  for (i =1;i<10001;i++){
    C[i] = C[i] + C[i-1];
  }
  for(i = n;i>0;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

int main(){
  unsigned short *A;
  unsigned short *B;
  int n;
  scanf("%d",&n);
  int i;
  A = malloc(sizeof(short)*(n+1));
  B = malloc(sizeof(short)*(n+1));
  for(i=1;i<=n;i++){
    scanf("%hu",&A[i]);
  }
  counting(A,B,n);
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}
