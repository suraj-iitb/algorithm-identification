#include<stdio.h>

int main(void){
  int n,a[100],i,j,count=0,min,temp,flag;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    min=i;
    flag=0;
    for(j=i;j<n;j++){
      if(a[j]<a[min]) {
	min=j;
	flag=1;
      }
    }
    if(flag==1){
    temp=a[min];
    a[min]=a[i];
    a[i]=temp;
    count++;
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",count);

  return 0;
}
