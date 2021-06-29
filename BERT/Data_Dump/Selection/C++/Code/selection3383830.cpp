#include<cstdio>
#include<algorithm>

using namespace std;

static const int MAX = 100;

int main() {
  int n, a[MAX], sw = 0;
  scanf("%d", &n);

  for ( int i = 0; i < n; i++ ) scanf("%d", &a[i]);

  for ( int i = 0; i < n; i++ ) {
    int min = i;
    for ( int j = i; j < n; j++ ) {
      if ( a[j] < a[min] ) min = j;
    }

    if (i != min) {
      swap(a[i], a[min]);
      sw++;
    }
  }

  for ( int i = 0; i < n; i++ ) {
    if ( i > 0 ) {
      printf(" ");
    }

    printf("%d", a[i]);
  }

  printf("\n");

  printf("%d", sw);

  printf("\n");

  return 0;
}

