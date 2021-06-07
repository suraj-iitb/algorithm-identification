#include <stdio.h>
#define N 100000
#define Q 500

int LinearSearch(int);
int S[N];
int n;

int main() {
  int i, q, C = 0;
  int T[Q];

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0; i<q; i++) {
    scanf("%d", &T[i]);
  }

  for(i=0; i<q; i++) {
    if(LinearSearch(T[i])==1)
      C++;
  }

  printf("%d\n", C);
  return 0;
}

int LinearSearch(int key) {
  int j = 0;
  S[n] = key;
  while(S[j]!=key)
    j++;
  if( j==n ) return 0;
  else return 1;
}
