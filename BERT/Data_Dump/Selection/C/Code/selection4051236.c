#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j,minj,N,A[100],tmp,cnt=0;

  scanf("%d",&N);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<N; i++){
    minj = i;
    for(j=i; j<N; j++){
      if(A[j]<A[minj]){
        minj = j;
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(tmp != A[i])cnt++;
  }

  for(i=0; i<N; i++){
    if(i!=0) printf(" %d",A[i]);
    else printf("%d",A[i]);
  }

  printf("\n%d\n",cnt);

  return 0;
}

