#include <stdio.h>
#include <stdlib.h>
int main() {
  int *a,n,j,i,minj;
  int count=0,tmp=0;
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  for (i = 0; i < n-1; i++) {
    minj=i;
    for (j = i ; j <n ; j++) {
      if (a[minj]>a[j]) {
        minj=j;}}
        tmp=a[i];
        a[i]=a[minj];
        a[minj]=tmp;
        if (i!=minj) count++;
  }
    for(i=0;i<n;i++){
      if (i!=n-1) printf("%d ",a[i]);
      else printf("%d\n",a[i]);
    }
    printf("%d\n",count);
  return 0;
}
