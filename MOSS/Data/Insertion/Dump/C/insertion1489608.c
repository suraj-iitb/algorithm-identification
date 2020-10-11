#include <stdio.h>
int main(void)
{
  int n;
  int a[1000];
  int i,j,k;
  int temp;

  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }

  
  for (i=0; i<n; i++) {
    if (i!=n-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }
  
  for (i=1; i<n; i++) {
    temp=a[i];
    j=i-1;
    while (j>=0 && a[j]>temp) {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
    for (k=0; k<n; k++) {
      if (k!=n-1) printf("%d ",a[k]);
      else printf("%d\n",a[k]);
    }
  }
  return 0;
}
