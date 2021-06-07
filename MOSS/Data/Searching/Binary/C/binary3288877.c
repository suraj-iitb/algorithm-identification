#include <stdio.h>
#define N 100000

int Search(int, int, int);

int S[N];

int main () {
  int n = 0, q = 0, cnt = 0, i;
  int T[50000];
 
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0 ; i < q ; i++) {
    scanf("%d",&T[i]);
  }

  for(i = 0 ; i < q ; i++) {
    if(Search(T[i], n, 0) == 1) cnt++;
  }

  printf("%d\n",cnt);

  return 0;

}

int Search(int x, int right, int left) {
  int mid = 0;

  mid = (right + left) / 2;

  if(left >= right) return 0;
  if(x == S[mid]) return 1;
  if(x > S[mid]) return Search(x, right, mid+1);
  else if(x < S[mid]) return Search(x, mid, left);
}

