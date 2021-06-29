#include<stdio.h>

int main(){
  int i,j,n,c=0,mini,t;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  for(i=0;i<n-1;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(a[j]<a[mini])mini=j;
    }
    t=a[i];
    a[i]=a[mini];
    a[mini]=t;
    if(i!=mini)c++;
  }

  
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",c);

  return 0;
}

