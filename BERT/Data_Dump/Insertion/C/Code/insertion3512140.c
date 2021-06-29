#include <stdio.h>
 
int main() {
  int n;
  scanf("%d",&n);
  int a[n],i,j;
  for(i=0; i<n; i++) scanf("%d",&a[i]);
 
  for(i=0; i<n; i++) {
    for(j=i-1; j>=0; j--) {
      if(a[j]>a[j+1]) {
    int tmp=a[j];
    a[j]=a[j+1];
    a[j+1]=tmp;
      } else break;
    }
    for(j=0; j<n; j++) {
      if(j) printf(" ");
      printf("%d",a[j]);
    }
    printf("\n");
  }
  return 0;
}
