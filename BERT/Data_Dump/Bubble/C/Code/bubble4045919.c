#include<stdio.h>
int main(){
  int N,data[100],flag,i,x,count=0;
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&data[i]);
  }
  flag=1;
  while(flag==1){
    flag=0;
    for(i=N-1; i>=1; i--){
      if(data[i]<data[i-1]){
	x=data[i];
	data[i]=data[i-1];
	data[i-1]=x;
	flag=1;
	count++;
      }
    }
  }
  
  for(i=0; i<N; i++){
    if(i==N-1) printf("%d",data[i]);
    else printf("%d ",data[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

