#include <stdio.h>
#define N 10000
#define Q 500
int linearSearch(int);
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
    k=linearSearch(T[i]);
    if(k > 0) c++;
  }
  printf("%d\n",c);
return 0;
}

int linearSearch(int key){
  int i;
  i=0;
  S[n]=key;
  while(S[i] != key) {
    i++;
    if(i == n) return 0;
  }
  return 1;
}
