#include<stdio.h>
#include<stdlib.h>
int bubbleSort(int *,int);
int num=0;
int main(){
  int i,N,*data;
  
  scanf("%d",&N);
  data=(int *)malloc(N*sizeof(data));

  for(i=0;i<N;i++){
    scanf("%d",&data[i]);
  }

  bubbleSort(data,N);

  for(i=0;i<N;i++){
    printf("%d",data[i]);
    if(i!=N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",num);
    
    return 0;
}

int bubbleSort(int *data,int N){
  int i,j,temp,flag=1;
  while(flag){
    flag=0;
    j=0;
    for(i=N-1;i>=j+1;i--){
      if(data[i]<data[i-1]){
	temp=data[i];
	data[i]=data[i-1];
	data[i-1]=temp;
	flag=1;
	num++;
      }
    }
    j++;
  }
  return *data;
}

