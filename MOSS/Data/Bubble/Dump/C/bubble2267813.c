#include <stdio.h>

int main(){
  int a[100];
  int n,i,j,count,flag,alt;

  flag=1;
  count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--)
      if(a[i]<a[i-1]){
	alt=a[i];
	a[i]=a[i-1];
	a[i-1]=alt;
	count++;
	flag=1;
      }
  }

  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],count);

  return 0;
}
	

  
