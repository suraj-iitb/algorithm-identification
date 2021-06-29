#include <stdio.h>
#define N 100
int main(){
  int a[N];
  int i,j,x,flag=1,c,d=0;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
  while(flag!=0){
    flag=0;
    for(j=x-1;j>=1;j--){
      if(a[j]<a[j-1]){
	c=a[j-1];
	a[j-1]=a[j];
	a[j]=c;
	flag=1;
	d++;
      }
    }
  }
  for(i=0;i<x-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[i],d);
  return 0;
}

