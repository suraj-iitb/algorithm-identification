#include <stdio.h>

int main(void)
{
  int n;
  int a[10000];
  int i,j,k;
  int minj;
  int temp;
  int cnt=0;

  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }

  for (i=0; i<n; i++) {
    minj=i;
    for (j=i; j<n; j++) {
      if (a[j]<a[minj]) {
        minj=j;
      }
    }
    if (minj!=i) {
      temp=a[minj];
      a[minj]=a[i];
      a[i]=temp;
      cnt++;
    }
  }

  for (i=0; i<n; i++) {
    if (i!=n-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }
  printf("%d\n",cnt);


  return 0;
}
