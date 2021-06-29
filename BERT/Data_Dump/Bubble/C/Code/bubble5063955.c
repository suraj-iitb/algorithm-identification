#include <stdio.h>

int main(void){
  int i,j,k,N,count=0,tmp;

  scanf("%d",&N);
  int data[N];
  for(i=0;i<N;i++) scanf("%d",&data[i]);

  for(i = 0 ;i < N; i++ ){
    for(j = N - 1 ;j > i ;j--){
      if(data[j] < data[j-1]){
	tmp = data[j];
	data[j] = data[j-1];
	data[j-1] = tmp;
	count++;
      }
    }
  }
  for(k=0;k<N-1;k++)printf("%d ",data[k]);
  printf("%d\n",data[N-1]);
  printf("%d\n",count);
}

