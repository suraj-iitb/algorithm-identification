#include <stdio.h>

int Bsort(int *,int );

int main(){
  int N,i,A[100],count;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  count=Bsort(A,N);
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

int Bsort(int *A,int N){
  int count = 0,hantei = 1,i,j,x;
  for(i=0;hantei==1;i++){
    hantei=0;
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	x=A[j-1];
	A[j-1]=A[j];
	A[j]=x;
	hantei=1;
	count++;
      }
    }
  }
  return count;
}

