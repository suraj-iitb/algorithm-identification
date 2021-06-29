#include<stdio.h>

int main(){
  int i,j;
  int N,M;
  int A[10000],B[10000],cmp,count=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  scanf("%d",&M);
  for(i=0;i<M;i++) scanf("%d",&B[i]);

  for(i=0;i<M;i++){
    cmp=B[i];
    for(j=0;j<N;j++){
      if(cmp==A[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);




  return 0;
}

