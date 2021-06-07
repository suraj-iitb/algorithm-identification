#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve(void){
    int n, q;
    scanf("%d\n", &n);
    int s[n];
    rep(n, i) scanf("%d ", &s[i]);
    scanf("\n");
    scanf("%d\n", &q);
    int t[q];
    rep(q, i) scanf("%d ", &t[i]);
    int bools[q];
    rep(q, i) bools[i] = binarysearch(t[i], s, n);
    int sum = 0;
    rep(q, i) sum += bools[i];
  printf("%d\n", sum);
}

int binarysearch(int a, int* xs, int len){
    if (len == 0) return 0;
    if (len == 1) {
        if (xs[0] == a) return 1; else return 0;
    }
    int mid = len / 2 + 1;
    int p = xs[mid-1];
    if (p == a) return 1;
    if (p > a) return binarysearch(a, &xs[0], mid - 1);
    else return binarysearch(a, &xs[mid], len - mid);
}

int main(void){
  solve();
  return 0;
}
