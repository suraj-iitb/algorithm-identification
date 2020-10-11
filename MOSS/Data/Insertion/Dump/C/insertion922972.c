#include <stdio.h>

static const int N = 1000;

void trace(int A[], int n) {
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(void) {
    int n, i, j, key;
    int a[N+1];
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    trace(a, n);
    for (i = 2; i <= n; i++) {
        key = a[i];
        j = i - 1;
        while (j > 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        trace(a, n);
    }

    return 0;
}
