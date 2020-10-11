#include <stdio.h>

int main(void)
{
  int n;
  int a[10000];
  int i,j;
  int temp;
  int flag;
  int cnt=0;

  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
  }

  flag=1;
  while(flag) {
    flag=0;
    for (j=n-1; j>0; j--) {
      if (a[j]<a[j-1]) {
        temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        flag=1;
        cnt++;
      }
    }
  }

  for (i=0; i<n; i++) {
    if (i!=n-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }
  printf("%d\n",cnt);

  return 0;
}
