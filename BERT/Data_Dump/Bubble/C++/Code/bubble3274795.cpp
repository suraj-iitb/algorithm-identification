#include<stdio.h>

int main(){
  int n,i,temp,cnt=0;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  int flag=1;
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	temp=a[i];
	a[i]=a[i-1];
	a[i-1]=temp;
	flag=1;
	cnt++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
	
    

