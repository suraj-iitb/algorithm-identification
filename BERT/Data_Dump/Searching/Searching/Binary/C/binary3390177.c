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
    int l=-1,r=n+1;
    while(l+1!=r) {
      int m=(l+r)/2;
      if(a[m]==x) {
	cnt++;
	break;
      }
      if(a[m]<x) l=m;
      else r=m;
    } 
  }
  printf("%d\n",cnt);
  return 0;
}

