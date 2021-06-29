#include<stdio.h>

int main(){
  int n,i,j;
  int minj=0,temp,cnt=0;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj])minj=j;
    }
      temp=a[i];
      a[i]=a[minj];
      a[minj]=temp;
      if(i!=minj)cnt++;
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
    printf("%d\n",cnt);
    return 0;
  }

