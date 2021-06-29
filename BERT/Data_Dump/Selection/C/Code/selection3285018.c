#include<stdio.h>
#include<stdlib.h>
int selectionSort(int *,int);
int main(){
  int i,N,*data,count;
  scanf("%d",&N);
  data=(int *)malloc(N*sizeof(data));
  for(i=0;i<N;i++){
    scanf("%d",&data[i]);
  }

  count=selectionSort(data,N);

  for(i=0;i<N;i++){
    printf("%d",data[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

int selectionSort(int *data,int N){
  int i,j,minj,temp,flag,count=0;
  for(i=0;i<N;i++){
    flag=0;
    minj=i;
    for(j=i;j<N;j++){
      if(data[j]<data[minj]){
	minj=j;
	flag++;
      }
    }
    if(flag!=0){
    temp=data[i];
    data[i]=data[minj];
    data[minj]=temp;
    count++;
    }
  }
  return count;
}

