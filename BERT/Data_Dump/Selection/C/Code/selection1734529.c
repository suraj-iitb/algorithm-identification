#include<stdio.h>
int main(){
  int i,j,A[101],minj,swap=0,a,N;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
    swap++;
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
