#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *, int);

int main(){
  int N, *data,i;
  scanf("%d",&N);
  
  data=(int *)malloc(N*sizeof(data));
  
  for(i=0;i<N;i++){
    scanf("%d",&data[i]);
  }
  
  insertionSort(data,N);
  free(data);
  return 0;
}
void insertionSort(int *data, int N){
  int key,i,j;
  for(i=0;i<N;i++){
    printf("%d",data[i]);
    if(i!=N-1){
      printf(" ");
    }
  }
  printf("\n");
  
  for(j=1;j<N;j++){
    key=data[j];
    i=j-1;
    while(i>=0&&data[i]>key){
      data[i+1]=data[i];
      i=i-1;
      data[i+1]=key;
    }
    for(i=0;i<N;i++){
      printf("%d",data[i]);
      if(i!=N-1){
	printf(" ");
      }
    }
    printf("\n");
  }
}


