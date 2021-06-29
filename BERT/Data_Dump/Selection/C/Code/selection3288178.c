#include <stdio.h>
int main(){
  int i,j,minj,N,tmp,flag,cnt=0,A[100];

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    flag = 0;
    minj = i;

    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	flag = 1;
	minj = j;
      }
    }

    if(flag==1) cnt++;

    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=(N-1)){
      printf(" ");
    }
  }
  printf("\n%d\n",cnt);

  return 0;
}

