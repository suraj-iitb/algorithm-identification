#include<stdio.h>
int main(){
  int N,A[1000],i,j,z,k;
 
    scanf("%d",&N);
    for(i=0; i<N; i++){
      scanf("%d",&A[i]);
    }
    for(k=0; k<N; k++){
      if(k==N-1)printf("%d",A[k]);
      else printf("%d ",A[k]);
    }
    printf("\n");
    for(i=1; i<=N-1; i++){
      z=A[i];
      j=i-1;
      while(j>=0 && A[j]>z){
	A[j+1]=A[j];
	j--;
	A[j+1]=z;
      }
      for(k=0; k<N; k++){
	if(k==N-1)printf("%d",A[k]);
	else printf("%d ",A[k]);
      }
      printf("\n");
    }
    return 0;
}

