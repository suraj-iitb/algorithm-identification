#include <stdio.h>

int main(){
  int i,j,a,flag=1,ch,N,cnt=0;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++) scanf("%d",&A[i]);

  while(flag == 1){
    flag = 0;
    for(j=N-1;j>a;j--){
      if(A[j] < A[j-1]){
	ch = A[j];
	A[j] = A[j-1];
	A[j-1] = ch;

	cnt++;
	flag = 1;
      }
    }
  }

  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d",A[N-1]);
  printf("\n%d\n",cnt);
  return 0;
}
  
	

