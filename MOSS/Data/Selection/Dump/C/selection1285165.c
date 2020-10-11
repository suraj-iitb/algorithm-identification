#include <stdio.h>

int main() {
  int n,a[101],i,j,m;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  int cnt=0;
  for(i=0; i<n; i++) {
    m=i;
    for(j=i+1; j<n; j++) {
      if(a[j]<a[m]) m=j;
    }
    if(a[i]>a[m]) {
      int tmp=a[i];
      a[i]=a[m];
      a[m]=tmp;
      cnt++;
    }
  }
  for(i=0; i<n; i++) {
    if(i) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}
