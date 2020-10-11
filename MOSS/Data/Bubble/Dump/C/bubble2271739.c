#include<stdio.h>

#define N 100

int main(){
  int i,j,n,num[N],tmp,count=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(num[j]<num[j-1]){
    tmp=num[j];
    num[j]=num[j-1];
    num[j-1]=tmp;
    count++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",num[i]);
  }
  printf("%d",num[n-1]);
  
  printf("\n%d\n",count);
  return 0;
}
