#include <stdio.h>
#define N 100

int main () {
  int i, j, n = 0, A[N], min = 0, cnt = 0, tmp = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i < n - 1 ; i++) {
    min = i;
    
    for(j = i ; j < n ; j++) {

      if(A[j] < A[min]) {
	min = j;
      }
    }
    tmp = A[i];
    A[i] = A[min];
    A[min] = tmp;

    if(A[i] != tmp) cnt++;
  }

  for(i = 0 ; i < n ; i++) {
    if(i == n - 1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }

  printf("%d\n",cnt);

  return 0;
}

