#include <stdio.h>
#define X 1000
int main(){
  int i,j,k=0,l,N,A[X],key,count=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(j=0;j<N;j++){
    for(i=0;i<N;i++){
      for(l=0;l<=count;l++){
	key=A[l];
	k=l-1;
	while(k>=0&&A[k]>key){
	  A[k+1]=A[k];
	  k--;
	}
	A[k+1]=key;
      }
      printf("%d",A[i]);
      if(i!=N-1)printf(" ");
    }
    ++count;
    printf("\n");
  }
  return 0;
}

