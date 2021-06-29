#include<stdio.h>
int main(){

  int i,j,n;
  int flag=0,swap,count=0;
  int minj,data[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(data[j]<data[minj]){
        flag=1;
	minj=j;
      }
    }
    if(flag==1){
      swap=data[i];
      data[i]=data[minj];
      data[minj]=swap;
      count++;
      flag=0;
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",data[i]);
    }
    else{
      printf("%d ",data[i]);
    }
  }
  printf("%d\n",count);
}

