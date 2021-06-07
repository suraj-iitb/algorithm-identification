#include <stdio.h>
#define N 10500


int main () {
  int n = 0, q = 0, cnt = 0, i, j;
  int S[N], T[500];
 
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(j = 0 ; j < q ; j++) {
    scanf("%d",&T[j]);
    S[i+j] = T[j];
  }

  i = 0;
  j = 0;

  while(j < q) {
    if(S[i] == T[j]) {
      j++;
      cnt++;
      i = 0;
    }
    else if(i < n + j - 1) i++;
    else {
      i = 0;
      j++;
    }
  }

  printf("%d\n",cnt);

  return 0;

}

