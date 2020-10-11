#include<stdio.h>
int main(){
  int N,X;
  int i,j,b=0;;
  int minj;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;++i){
    minj=i;
    for(j=i;j<N;++j){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
    X=A[i];
    A[i]=A[minj];
    A[minj]=X;
    b++;
    }
  }
  
    
    for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i==N-1){
      break;
    }
    printf(" ");

  }
  printf("\n%d\n",b);

  return 0;
}

