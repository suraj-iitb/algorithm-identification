#include <stdio.h>

void bubbleSort(int A[],int N){
  int i,flg=1;
  int count=0;
  int tmp;
  while(flg){
    flg=0;
    for(i=N-1;i>=1;i--){
      if(A[i]<A[i-1]){
	tmp=A[i-1];
	A[i-1]=A[i];
	A[i]=tmp;
	flg=1;
	count++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);
}

int main(void){
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  bubbleSort(a,n);
  return 0;
}
