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
    for(j=0; j<N; j++) {
      if(a[j]==x) {
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}



