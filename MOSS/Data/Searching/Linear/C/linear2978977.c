#include<stdio.h>

int main() {
  int i,n,q,key,S[10000],answer = 0;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++) {
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++) {
    scanf("%d",&key);
    if(search(S, n, key))
      answer++;
  }
  printf("%d\n", answer);
  return 0;
}

int search(int S[], int n, int key) {
  int i=0;

  S[n] = key;
  while(S[i] != key)
    i++;
  return i != n;
}

