#include<stdio.h>
int main(){
  int i,j,A[101],a,swap=0,N;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	swap++;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",swap);
  return 0;
}
