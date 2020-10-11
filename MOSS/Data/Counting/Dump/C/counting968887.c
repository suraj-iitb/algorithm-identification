#include<stdio.h>
#define N 2000000
int a[N],b[N],c[N];
int main(){
  int i,j,k=0,n;
  
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    c[a[i]]++;
    
    if(k<a[i])k=a[i];
  }
  for(i=1;i<=k;i++){
    c[i]+=c[i-1];
  }

  for(i=0;i<n;i++){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
  for(i=0;i<n;i++){
    if(i!=n-1)
      printf("%d ",b[i]);
    else printf("%d\n",b[i]);
    
  }
  
  
  return 0;
}
