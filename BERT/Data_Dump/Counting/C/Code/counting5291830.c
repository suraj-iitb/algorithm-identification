#include <stdio.h>
#define N 2000001

int A[N], B[N], C[10001];

void counting_sort(int k, int n){
  int i;
  for(i=0;i<=k;i++) C[i] = 0;
  for(i=0;i<n;i++) C[A[i]]++;
  for(i=1;i<=k;i++) C[i] += C[i-1];
  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

main(){
  int n, k = 0, i;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
    if(k < A[i]) k = A[i];
  }
  counting_sort(k, n);
  printf("%d", B[0]);
  for(i=1;i<n;i++) printf(" %d", B[i]);
  printf("\n");
  return 0;
}
