#include <stdio.h>

int main(){

  int h,i,j,k,flag,N,cnt=0;

  scanf("%d",&N);
  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	h=A[j];
	A[j]=A[j-1];
	A[j-1]=h;
	flag=1;
	cnt++;
      }
    }
    i++;
  }

  printf("%d",A[0]);
  for(k=1;k<N;k++){
    printf(" %d",A[k]);
  }
  printf("\n%d\n",cnt);

  return 0;
}
    
	

