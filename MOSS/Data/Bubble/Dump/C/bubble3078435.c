#include<stdio.h>
#include<stdlib.h>
int main() {
  int n,i,a[100],ire,k=0,j;
  
  scanf("%d",&n);
  if(n<1 || 100<n) exit(0);
  
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
    if(a[i]<0 || 100<a[i]) exit(0);
  }

  for(i=0;i<n;i++) {
    for(j=n-1;j>=1;j--) {
    if(a[j]<a[j-1]){
      ire=a[j-1];
    a[j-1]=a[j];
    a[j]=ire;
    k++;
    }
    }
  }

  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",k);
  return 0;
}

