#include <stdio.h>

int main(){

  int h,i,j,k,minj,N,cnt=0;

  scanf("%d",&N);
  int A[N];

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
    if(minj!=i){
      h=A[i];
      A[i]=A[minj];
      A[minj]=h;
      cnt++;
    }
  }

  printf("%d",A[0]);
  for(k=1;k<N;k++){
    printf(" %d",A[k]);
  }
  printf("\n%d\n",cnt);

  return 0;
}

