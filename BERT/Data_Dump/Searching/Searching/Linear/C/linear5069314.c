#include<stdio.h>

int linearsearch(int A[],int N,int key){
  int i;
  i = 0;
  A[N] = key;
  while(A[i]!=key){
    i++;
  }
  return i;
}


int main(){
  int i,N,M,key,num = 0;
  int k = 0;
  int A[10000];

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&M);

  for(i = 0; i<M; i++){
    scanf("%d",&key);
    k = linearsearch(A,N,key);
    if(k!=N){
      num++;
      }
    }
    
  printf("%d\n",num);

  return 0;
}
