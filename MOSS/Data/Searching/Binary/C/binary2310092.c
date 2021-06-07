#include <stdio.h>
#define N 100000
#define Q 50000
int binarySearch(int);
int n,S[N];
int main() {
  int i,q,c=0,T[Q],k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++) {
    k=binarySearch(T[i]);
    if(k > 0) c++;
  }
  printf("%d\n",c);
  return 0;
}

int binarySearch(int key) {
  int l,m,r;
  l = 0;
  r = n;
  while(l < r) {
    m = (l + r) /2;
    if(S[m] == key) return 1;
    else if(key < S[m]) r = m;
    else l = m + 1;
  }
  return 0;
}
