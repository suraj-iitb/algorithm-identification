#include <stdio.h>
#define N 100

void trace(int A[], int length, int index) {
  int i;
  for (i = 0; i < length -1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);
  printf("%d\n", index);
}

int main() {
  int length, j, tmp;
  int flag = 1, i =0;
  int A[N];
  scanf("%d", &length);
  for(j = 0; j < length; j++) {
    scanf("%d", &A[j]);
  }

  while(flag) {
    flag = 0;
    for(j = length - 1; j > 0; j--) {
      if(A[j] < A[j-1]) {
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        i++;
      }
    }
  }
  trace(A, length, i);
  return 0;
}
