#include<stdio.h>
int main(){

  int i,j,n;
  int count=0,swap,data[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(data[j]<data[j-1]){
	swap=data[j];
	data[j]=data[j-1];
	data[j-1]=swap;
	count++;
      }
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
  return 0;
}

