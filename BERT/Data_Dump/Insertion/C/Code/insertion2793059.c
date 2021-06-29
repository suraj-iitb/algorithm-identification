#include<stdio.h>
int main(){

  int a[100]={0},i,j,k,v,n;
  
  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  for(k=0;k<n-1;k++) printf("%d ",a[k]);printf("%d\n",a[n-1]);

  for(i=1;i<=n-1;i++){
    v = a[i];
    j = i - 1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
      a[j+1]=v;
    }
    for(k=0;k<n-1;k++) printf("%d ",a[k]);printf("%d\n",a[n-1]);
  }
}
