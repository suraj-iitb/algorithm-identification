#include <stdio.h>
#define N 10000

int linearSearch(int A[], int key, int k){
    int i;
    for(i = 0; i < k; i++){
      if(A[i] == key) return 1;
    }
    return 0;
  }

int main(void){
  int S[N], n, q, cnt = 0, i, x;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&x);
    cnt += linearSearch(S, x, n);
  }

  printf("%d",cnt);
  printf("\n");
}


