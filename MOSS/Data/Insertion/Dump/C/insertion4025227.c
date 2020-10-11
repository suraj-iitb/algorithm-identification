#include<stdio.h>
int main(){
  int N,i,j,A[1000],key;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
    for(i=0;i<=N-1;i++){
      key=A[i];
      j=i-1;
      while(j>=0&&A[j]>key){
	A[j+1]=A[j];
	j=j-1;
      }
      A[j+1]=key;
      for(j=0;j<N-1;j++){
	printf("%d ",A[j]);
      }
      printf("%d\n",A[j]);
    }
    return 0;
}

