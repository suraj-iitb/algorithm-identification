#include<stdio.h>

int main(){
  int A[100];
  int a,i,j,minj=0,t;
  int N,count=0;

  scanf("%d",&N);
  for(a=0;a<N;a++){
    scanf("%d",&A[a]);
  }
  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]) minj = j;     
    }
    if(minj!=i){
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    count++;
    }
  }
  for(a=0;a<N-1;a++){
    printf("%d ",A[a]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}

