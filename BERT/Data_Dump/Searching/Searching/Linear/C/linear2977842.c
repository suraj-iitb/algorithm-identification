// linear search
#include <stdio.h>

int main() {
  int a[10000];
  int b[500];
  int i, j, n, q;
  int cnt = 0;

  // input the number
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // input the search number
  scanf("%d", &q);

  for(i = 0; i < q; i++) {
    scanf("%d", &b[i]);
  }

  // search
  for(i = 0; i < q; i++) {
    for(j = 0; j < n; j++) {
      if(b[i] == a[j]) {
	cnt++;
	break;
      }
    }
  }

  printf("%d\n", cnt);
  
  return 0;
}

