#include<stdio.h>

int main(){
  int i,j,a,N,v;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  for(i=1;i<N;i++){
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(a=0;a<N-1;a++){
      printf("%d ",A[a]);
    }
    printf("%d\n",A[N-1]);
  }
  return 0;
}

