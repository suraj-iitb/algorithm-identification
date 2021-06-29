#include<cstdio>
#include<algorithm>
using namespace std;

static const int MAX = 100;

int main() {
  int n, a[MAX], count = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if ( a[j] < a[j - 1] ) {
        swap(a[j], a[j - 1]);
        count++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }

    printf("%d", a[i]);
  }

  printf("\n");

  printf("%d", count);

  printf("\n");

  return 0;
}

