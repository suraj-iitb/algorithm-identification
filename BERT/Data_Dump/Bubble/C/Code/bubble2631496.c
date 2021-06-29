#include <stdio.h>

int main(){
  int N,i,count=0;;
  scanf("%d",&N);
  int A[N];
  for(i=0; i<N; i++)
    scanf("%d",&A[i]);
  int flag = 1;
  while(flag){
    flag = 0;
    for(int j=N-1; j>=1;j--){
      if(A[j] < A[j-1]){
	int v;
	v = A[j];
	A[j] = A[j-1];
	A[j-1] = v;
	flag = 1;
	count++;
      }
    }
  }
  for(i=0; i<N-1; i++)
    printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}
