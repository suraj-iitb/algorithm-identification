#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i, n, flag = 1, tmp, count = 0;
  int A[100];

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  while(flag) {
    flag = 0;
    for(i = n - 1; i > 0; i--) {
      if(A[i] < A[i - 1]){
        tmp = A[i];
        A[i] = A[i - 1];
        A[i - 1] = tmp;
        flag = 1;
        count++;
      }
    }
  }

  for(i = 0; i < n; i++) {
    printf("%d", A[i]);
    if(i != n - 1) printf(" ");
    else printf("\n");
  }
  printf("%d\n", count);

  return 0;
}
