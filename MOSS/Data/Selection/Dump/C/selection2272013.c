#include<stdio.h>
#define k 100
int main(){
  int N,A[k],i,j,minj,atai,cou=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);

  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
      
    }
    if(A[i]>A[minj]){
      cou++;
    atai=A[i];
    A[i]=A[minj];
    A[minj]=atai;
    }
  }
  for(i=0;i<N;i++){
  printf("%d",A[i]);
  if(i!=N-1)printf(" ");
  }
  printf("\n%d\n",cou);
  return 0;
}
