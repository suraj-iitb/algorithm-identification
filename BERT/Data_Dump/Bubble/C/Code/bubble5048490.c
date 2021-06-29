#include <stdio.h>
#define SWAP(a,b) (a += b, b = a-b, a -= b)

int main(){
  int i, j, N, cnt=0;
  int A[100];

  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  for(i = 0; i < N; i++){
    for(j = N-1; j > i; j--){
      if (A[j] < A[j-1]) {
	SWAP(A[j], A[j-1]);
	cnt++;
      }
    }
}
    
  for(i = 0; i < N; i++){
    if (i == N-1){
      printf("%d\n",A[i]);
      break;
    }
   else printf("%d ", A[i]);
  }
  printf("%d\n", cnt);

  return 0;
}

