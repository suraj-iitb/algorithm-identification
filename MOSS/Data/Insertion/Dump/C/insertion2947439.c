#include <stdio.h>

int main(){
  int i,N,j;
  int v,A[1000];
  scanf("%d",&N);

  for(i=0;i<=N-1;i++){
    scanf("%d", &A[i]);
    if(i==N-1){
    printf("%d\n",A[i]);
    }
    else{
      printf("%d ",A[i]);
    }
  }
  
   for(i=1; i<=N-1;i++){
    v=A[i];
    j = i-1;
     while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
     }
      for(j=0;j<N;j++){
	if(j==N-1){
       printf("%d\n",A[j]);
	}
	else {
	  printf("%d ",A[j]);
	}
     }
    }
   return 0;
}

