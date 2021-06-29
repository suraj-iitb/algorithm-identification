#include <stdio.h>

int main(){

  int i,N,j,minj,count=0,A[100],tmp,flag=0;
  scanf("%d",&N);

  for(i=0;i<N;i++){

    scanf("%d",&A[i]);

  }

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i+1;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    count++;
    flag=0;
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
}
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}

