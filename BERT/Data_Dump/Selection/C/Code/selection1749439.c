#include<stdio.h>
#define N 100

int main(){
  int min,i,j,num[N],tmp,count=0,n;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)scanf("%d",&num[i]);
  
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(num[min]>num[j])min=j;
   }
    if(i!=min){
      tmp=num[i];
      num[i]=num[min];
      num[min]=tmp;
      count++;
    }
  }
  
  for(i=0;i<n-1;i++)printf("%d ",num[i]);
  printf("%d\n%d\n",num[i],count);
  
  return 0;
}
