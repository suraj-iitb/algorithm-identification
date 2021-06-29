#include <stdio.h>
#include <stdlib.h>
int main() {
  int *a,n,j,i;
  int count=0,tmp=0;
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = n-1 ; j >=1 ; j--) {
      if (a[j]<a[j-1]) {
        tmp=a[j-1];
        a[j-1]=a[j];
        a[j]=tmp;
        count++;
      }
    }
}
  for(i=0;i<n;i++){
    if (i!=n-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }
  printf("%d\n",count);
  return 0;
}
