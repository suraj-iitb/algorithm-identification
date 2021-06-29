#include<stdio.h>
#include<stdlib.h>

int main() {
  int i ,n , a[100],j,min,k=0,ire,t,ff;
  scanf("%d",&n);
  if(n<1 || 100< n) exit(0);

  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++) {
    min = i;
    ff=0;
    for(j=i+1;j<n;j++) {

      if(a[j]<a[min]) {
	min=j;
	ff=1;
    }
    }
      if(ff==1) {
      ire=a[i];
      a[i]=a[min];
      a[min]=ire;
      k++;
      }
  }

  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",k);
  return 0;
}

