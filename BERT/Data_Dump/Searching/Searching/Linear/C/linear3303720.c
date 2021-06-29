#include<stdio.h>

int search(int A[],int N,int key){
  int i=0;
  A[N]=key;
  while(A[i] !=key)
    i++;
  return i !=N;
}

int main(){
  int i,N,M,A[10001],key,k=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&M);
  for(i=0;i<M;i++){
    scanf("%d",&key);
    if(search(A,N,key))
      k++;
  }
  printf("%d\n",k);

  return 0;
}
