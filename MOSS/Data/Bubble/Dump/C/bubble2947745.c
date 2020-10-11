#include<stdio.h>
#define N 100


int main(){
  int x[N];
  int n,i,c,flag=1,count=0;
  
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&x[i]);
  }
  
  while(flag){
    flag=0;
    for(i=n-1 ; i>0 ; i--){
      if(x[i]<x[i-1]){
	c = x[i];
	x[i]=x[i-1];
	x[i-1]=c;
	count++;
	flag=1;
      }
    }
  }
  for(i=0 ; i<n ; i++){
    if(i<n-1) printf("%d ",x[i]);
    else printf("%d\n",x[i]);
  }
  printf("%d\n",count);
}

