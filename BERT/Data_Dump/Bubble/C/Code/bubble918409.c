#include<stdio.h>
#include<stdlib.h>

void swap(int *,int *);

int main(void){
  int N,work,cnt=0;
  int *data;
  int i,j;

  scanf("%d",&N);

  data=(int *)malloc(sizeof(int)*N);

  for(i=0;i<N;i++){
    scanf("%d",&data[i]);
  }

  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(data[j-1]>data[j]){
	cnt++;
	swap(&data[j-1],&data[j]);
      }
    }
  }

  printf("%d",data[0]);
  for(i=1;i<N;i++) printf(" %d",data[i]);
  printf("\n%d\n",cnt);

  free(data);

  return 0;
}

void swap(int *a,int *b){
  int work;

  work=*a;
  *a=*b;
  *b=work;
}
