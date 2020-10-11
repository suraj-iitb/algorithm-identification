#include<stdio.h>
int main(){
  int N,A[100],i,j,minj,x,count=0;
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<=N-1; i++){
    minj=i;
    for(j=i; j<=N-1; j++){
      if(A[j]<A[minj]){
	 minj=j;
      }
    }
    if(i!=minj){
        x=A[i];
        A[i]=A[minj];
        A[minj]=x;
        count++;
    }
  }

  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[N-1]);
  printf("\n");
  printf("%d\n",count);
  return 0; 
}
