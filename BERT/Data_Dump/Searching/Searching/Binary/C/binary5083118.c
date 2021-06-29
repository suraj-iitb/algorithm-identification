#include <stdio.h>

int main() {
  int N,M,i,j,cnt=0;
  scanf("%d",&N);
  int a[N];
  for(i=0; i<N; i++) scanf("%d",&a[i]);
  scanf("%d",&M);
  for(i=0; i<M; i++) {
    int x;
    scanf("%d",&x);
    int l=-1,r=N+1;
    while(l+1!=r) {
      int M=(l+r)/2;
      if(a[M]==x) {
	cnt++;
	break;
      }
      if(a[M]<x) l=M;
      else r=M;
    } 
  }
  printf("%d\n",cnt);
  return 0;
}

