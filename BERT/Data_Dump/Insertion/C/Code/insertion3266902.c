#include<stdio.h>
int main(){
  int i,j,N,A[101],v,a;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>=v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(a=0;a<N;a++){
      printf("%d",A[a]);
      if(a != N-1)
	printf(" ");
    }
    printf("\n");
  }
  return 0;
}

