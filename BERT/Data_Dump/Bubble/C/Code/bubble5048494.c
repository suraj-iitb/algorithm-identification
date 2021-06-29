#include <stdio.h>

int main(){
  int i,j,A[100],N,flag,k=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	flag=A[j];
	A[j]=A[j-1];
	A[j-1]=flag;
	k++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i==N-1) break;
    else printf(" ");
  }
  printf("\n");
  printf("%d\n",k);
  
  return 0;
}
