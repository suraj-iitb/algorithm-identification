#include<stdio.h>

int main(){
  int i,j,n,v,a[1000];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    v=a[i];
    j=i-1;
    while(1){
      if(j<0 || a[j]<=v)break;
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(j=0;j<n;j++){
      if(j<n-1)printf("%d ",a[j]);
      else printf("%d\n",a[j]);
    }
  }
  return 0;
}
