#include<stdio.h>

int main(void){
  int N,i,j,key,count=0;
  int length[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&length[i]);
  }
  
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>i;j--){
      if(length[j]<length[j-1]){
	key=length[j];
	length[j]=length[j-1];
	length[j-1]=key;
	count++;
      }
    }
  }
  
  for(i=0;i<N;i++){
    printf("%d",length[i]);
    if(i<N-1) printf(" ");
  }
  
  printf("\n%d\n",count);
  return 0;
}
