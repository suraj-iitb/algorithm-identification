#include<stdio.h>
int main(){
  int i,j,s=0,minj,exch,N,A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(A[i]!=A[minj]){
      s++;
    }
    exch=A[i];
    A[i]=A[minj];
    A[minj]=exch;
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n%d\n",s);
}

