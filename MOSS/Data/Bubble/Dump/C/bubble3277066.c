#include<stdio.h>
#define N 100
int main(){
  int a[N],x,i,flag=0,num,num1=0;

  scanf("%d",&x);
  for(i=0;i<x;i++)
    scanf("%d",&a[i]);
  while(1){
    flag=0;
    for(i=x-1;i!=0;i--){
      if(a[i]<a[i-1]){
	num=a[i-1];
	a[i-1]=a[i];
	a[i]=num;
	flag=1;
	num1++;
	continue;
      }
    }
    if(flag==0)
      break;
  }
  for(i=0;i<x;i++){
    if(i==x-1){
      printf("%d",a[i]);
      break;
    }
    printf("%d ",a[i]);
  }
  printf("\n");
  printf("%d\n",num1);
  return 0;
}
    

