#include"stdio.h"

#define rep(i, n) for(int i = 0; i < (int)n; i++)

const int MAX = 100100;

int linearSearch(int S[], int n, int key){
  rep(i, n)
    if (S[i] == key)
      return 1;
  return 0;
}

int main(){

  int n;
  scanf("%d", &n);
  int S[MAX];
  rep(i, n) scanf("%d", &S[i]);

  int q;
  scanf("%d", &q);
  int T[MAX];
  rep(i, n) scanf("%d", &T[i]);

  int ans = 0;
  rep(i, q){
    ans += linearSearch(S, n, T[i]);
  }

  printf("%d\n", ans);

  return 0;
}
