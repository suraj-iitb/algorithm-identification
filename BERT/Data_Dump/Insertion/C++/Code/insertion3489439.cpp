#include <stdio.h>

int main (void){
  int n,a[1001],h,i,j,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=1;i<=n;i++){
    for(h=0;h<n;h++){
      printf("%d",a[h]);
      if(h!=n-1) printf(" ");
    }
    printf("\n");
    v=a[i];
    j=i-1;
    if(i!=n){
      while(j>=0 && a[j]>v){
	a[j+1]=a[j];
	j--;
      }
      a[j+1]=v;
    }
  }
  return(0);
}

