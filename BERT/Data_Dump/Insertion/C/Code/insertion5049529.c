#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,i,j,v,k,*a;

  scanf("%d",&n);
  
  a=(int *)malloc(n*sizeof(int));
  
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<n;i++){
    for(k=0;k<n;k++){
      if(k!=n-1)printf("%d ",a[k]);
      else printf("%d\n",a[k]);
    }
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
  }
  for(k=0;k<n;k++){
      if(k!=n-1)printf("%d ",a[k]);
      else printf("%d\n",a[k]);
    }
  return 0;
}

