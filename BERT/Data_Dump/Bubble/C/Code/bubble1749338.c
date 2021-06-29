#include<stdio.h>
#define N 100

int main(){
  int n,num[N],i,flag,tmp,count=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)scanf("%d",&num[i]);
  
  flag=1;
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(num[i]<num[i-1]){
      tmp=num[i];
      num[i]=num[i-1];
      num[i-1]=tmp;
      flag=1;
      count++;
      }
    }
  }
  
  for(i=0;i<n-1;i++)printf("%d ",num[i]);
  printf("%d\n%d\n",num[i],count);
  
  return 0;
}
