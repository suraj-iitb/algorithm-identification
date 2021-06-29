#include<stdio.h>
#include<stdlib.h>

void swap(int*,int*);

int main(){

  int N,minj,cnt=0;
  int i,j;

  scanf("%d",&N);

  if(N<1&&N>100)exit(1);
  
  int inp[N];

  for(i=0;i<N;i++){
    scanf("%d",&inp[i]);
    if(inp[i]<1&&inp[i]>100)exit(2);
  }

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(inp[j]<inp[minj]){
	minj = j;	
      }
    }
    if(i!=minj){
    swap(&inp[i],&inp[minj]);
    cnt++;}
  }

  for(i=0;i<N;i++){
      printf("%d",inp[i]);
      if(i<N-1){
	printf(" ");
      }
    }

    printf("\n");

    printf("%d\n",cnt);

  return 0;
}

void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

