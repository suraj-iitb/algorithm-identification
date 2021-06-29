#include<stdio.h>
int main(){
  int N,A[100],temp,count=0,i,j,k;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	  temp=A[j-1];
	  A[j-1]=A[j];
	  A[j]=temp;
	  count++;
      }
    }
  }
  for(k=0;k<N-1;k++) printf("%d ",A[k]);
  printf("%d",A[N-1]);
  printf("\n%d\n",count);
  return 0;
}

