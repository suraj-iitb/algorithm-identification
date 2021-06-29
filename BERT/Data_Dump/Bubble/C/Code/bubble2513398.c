#include<stdio.h>
#define N 100
 
int main(void){
  int i,j,tmp,n,count=0,flag=1,data[N];
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&data[i]);
 
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(data[j]<data[j-1]){
        tmp=data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
        count++;
        flag=1;
      }
    }
  }
 
  for(i=0;i<n;i++){
    printf("%d",data[i]);
    if(i!=n-1) printf(" ");
  }
 
  printf("\n");
  printf("%d\n",count);
  return 0;
}
