#include<stdio.h>
#define SWAP(a,b) (a += b,b = a - b,a -= b)
int main(){
  int flag=1;
  int N;
  int i,j,b=0;;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	SWAP(A[j],A[j-1]);
	b++;
	flag=1;
      }
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

