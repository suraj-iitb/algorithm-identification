#include<stdio.h>
int main(){
  int i,j,n,b,num=0;
  scanf("%d",&n);
  if(n<1||n>100)return 0;
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	b=a[j];
	a[j]=a[j-1];
	a[j-1]=b;
	flag=1;
	num++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",num);
  return 0;
}

