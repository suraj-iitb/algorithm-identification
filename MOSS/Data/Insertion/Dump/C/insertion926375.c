#include<stdio.h>
#include<stdlib.h>
 
int main(void){
  int N,key;
  int *data;
  int i,j;
 
  scanf("%d",&N);
 
  data=(int *)malloc(N*sizeof(int));
 
  for(i=0;i<N;i++) scanf("%d",&data[i]);
 
  printf("%d",data[0]);
  for(i=1;i<N;i++){
    printf(" %d",data[i]);
  }
  printf("\n");
 
  for(i=1;i<N;i++){
    key=data[i];
    j=i-1;
    while(j>=0 && data[j]>key){
      data[j+1]=data[j];
      j--;
    }
    data[j+1]=key;
     
    printf("%d",data[0]);
    for(j=1;j<N;j++){
      printf(" %d",data[j]);
    }
    printf("\n");
  }
 
  free(data);
 
  return ;
}
