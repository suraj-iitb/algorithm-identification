#include <stdio.h>
#include <stdlib.h>
#define N 100
#define A 1000

int main(void){
  int n,i,temp,j,k;
  int a[N];

  scanf("%d",&n);
  if(n<0||n>N)exit(1);  
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(k=0;k<n;k++){
    if(k!=n-1) printf("%d ",a[k]);
    else printf("%d\n",a[k]);
  }
  for(j=1;j<n;j++){
    temp=a[j];
    i=j-1;
    while(i>=0 && a[i] > temp){
      a[i+1]=a[i];
      i=i-1;
    }
    a[i+1]=temp;
    for(k=0;k<n;k++){
      if(k!=n-1) printf("%d ",a[k]);
      else printf("%d\n",a[k]);
    }
  }
    return 0;
}
