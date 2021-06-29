#include <stdio.h>

int main() {
  int n,m,i,j,cnt=0;
  scanf("%d",&n);
  int a[n];
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%d",&m);
  for(i=0; i<m; i++) {
    int x;
    scanf("%d",&x);
    for(j=0; j<n; j++) {
      if(a[j]==x) {
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
