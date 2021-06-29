#include<stdio.h>
#define N 100

int main(){

  int i,j,l,n,v,num[N],c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

  for(i=0;i<n;i++){
    l=i;
    for(j=i;j<n;j++){
      if(num[j]<num[l])l=j;
    }
    if(i!=l){
      v=num[i];
      num[i]=num[l];
      num[l]=v;
      c++;
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",num[i]);
  }
  printf("%d\n%d\n",num[n-1],c);
  return 0;
}

