#include <stdio.h>
int main (){
  int n,x[100],i,j,flag=0,tmp,cnt=0,min;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(x[j]<x[min]){
	min=j;
      }
    }
    if(i!=min){
      cnt++;
    }
    tmp=x[i];
    x[i]=x[min];
    x[min]=tmp;
  }
  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%d",x[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

