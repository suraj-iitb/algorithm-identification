#include<stdio.h>
int main(){
  int i,j,minj,N,count=0,v,flag;
  int data[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&data[i]);
  }

  for(i=0;i<N-1;i++){
    minj=i;
    flag=0;
    for(j=i;j<N;j++){
      if(data[j]<data[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
    v=data[i];
    data[i]=data[minj];
    data[minj]=v;
     count++;
    }
  }

  for(i=0;i<N;i++){
    printf("%d",data[i]);
    if(i!=N-1)printf(" ");
  }

  printf("\n");
  printf("%d\n",count);
  return 0;

}

