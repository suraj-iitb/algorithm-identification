#include<stdio.h>

int main(void){
  int flag,i,n,a[100],count=0,temp,j;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  flag=1;
  j=0;
  while(flag){
    flag=0;
    for(i=n-1;i>=j+1;i--){
      if(a[i]<a[i-1]){
        temp=a[i];
        a[i]=a[i-1];
        a[i-1]=temp;
        count++;
        flag=1;
      }
    }
    j++;
  }
  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",count);
  return  0;
}
