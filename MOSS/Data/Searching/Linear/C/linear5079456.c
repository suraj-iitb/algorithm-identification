#include <stdio.h>

#define L 1000000

int main() {

  int n,S[L],q,T[L];
  int i,j,num=0;

  scanf("%d", &n);

  for( i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  for ( i = 0; i < q; i++) {
    for ( j = 0; j < n; j++) {

      if (T[i]==S[j]) {
        num++;
        break;
      }
    }
  }

  printf("%d\n", num);

  return 0;
}

