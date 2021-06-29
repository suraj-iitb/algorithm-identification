#include<stdio.h>

#define N 100

int main(){
  int i,j,num[N],n,min,tmp,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(num[j]<num[min]){
	min=j;
      }
    }
    if(min != i){
    tmp=num[i];
    num[i]=num[min];
    num[min]=tmp;
    count++;
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",num[i]);
  }
  printf("%d\n",num[n-1]);
  printf("%d\n",count);
  return 0;
}
