#include<stdio.h>

int A[2000000], B[2000000];

int main(){
  int C[10000], D[10000];
  int n, i, a;

  scanf("%d",&n);

  for(i = 0; i < 10000; i++) C[i] = 0;

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
    C[A[i]]++;
  }

  D[0] = 0;

  for(i = 1; i < 10000; i++) D[i] = D[i - 1] + C[i - 1];

  for(i = 0; i < n; i++){
    a = A[i];
    B[D[a]] = a;
    D[a]++;
  }

  for(i = 0; i < n; i++){
    printf("%d",B[i]);
    if(i != n - 1) printf(" ");
  }

  printf("\n");

  return 0;
}
