#include<stdio.h>
#define N 100
int main(){
  int a[N],x,i,j,flag=0,flag1=0,num,num1=0,min;

  scanf("%d",&x);
  for(i=0;i<x;i++)
    scanf("%d",&a[i]);
    
  for(i=0;i<x;i++){
    flag=0;
    flag1=0;
    min=i;
    for(j=i;j<x;j++){
      if(a[j]<a[min]){
	min=j;
	flag=1;	  
      }	
    }
    if(flag==1){
      num=a[i];
      a[i]=a[min];
      a[min]=num;
      num1++;
    }
      
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
    
	
		 
  

