#include <stdio.h>

int main(){
  int N,i,j,cnt=0,tmp=0,minj=1,A[100];
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    minj=i;

    for(j=i;j<N;j++){
      
      if (A[j]<A[minj]){
	minj=j;

      }
    }
    if(A[i]!=A[minj]){
	tmp=A[i];   //A[i] と A[minj] を交換
	A[i]=A[minj];
	A[minj]=tmp;
	cnt++;
    }
  }
  
   for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);

  return 0;

}

