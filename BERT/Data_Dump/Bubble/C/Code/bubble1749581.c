#include <stdio.h>

int main() {
  int a[100],n,i,flag,count,change;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  flag = 1;
  count = 0;

  while(flag) {
    flag = 0;
    for(i=n-1;i>0;i--) {
      if(a[i] < a[i-1]) {
	change = a[i];
	a[i] = a[i-1];
	a[i-1] = change;
	flag = 1;
	count++;
      }
    }
  }
  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}
