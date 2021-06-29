#include<stdio.h>
int main(){
  int n,i,j,min,b,c=0;
  scanf("%d",&n);
  if(n<0||n>100)return 0;
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min])min=j;
    }
    if(a[i]==a[min]);
    else{b=a[i];
    a[i]=a[min];
    a[min]=b;
    c++;}
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
    }
  printf("%d\n",c);
  return 0;
}

