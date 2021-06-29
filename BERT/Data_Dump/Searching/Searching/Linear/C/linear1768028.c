#include<stdio.h>
#define N 10000
#define Q 500

int search(int);
int S[N];
int n;

int main() {
  int q,T[N],i,j,x,count=0;
  scanf("%d",&n);
  for(i = 0; i< n; i++) {
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++) {
    scanf("%d",&T[i]);
  }
  for(i = 0; i < q; i++) {
    x = search(T[i]);
    if(x >= 0 && x < n ) {
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}

int search(int key) {
  int i = 0;
  S[n] = key;
  while(S[i] != key) {
    i++;
    if(i ==n) {
      return n;
    }
  }
  return i;
} 
