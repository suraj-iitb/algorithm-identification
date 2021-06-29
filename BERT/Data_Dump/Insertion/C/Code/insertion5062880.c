#include <stdio.h>

int main(){
  int N;
  int A[100];
  int v,i,j,k;
  int m=1,n=2,l;

  for(l=0;l<50;l++){
    l=l+m;
      }

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>=v+1){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k+1<=N-1)
	printf(" ");
    }
    printf("\n");
  }

  return 0;
}

