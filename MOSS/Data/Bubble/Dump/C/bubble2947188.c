#include<stdio.h>
int BubbleSort(int A[],int N){
  int i,j,temp,cnt=0;
  for(i=0;i<N-1;i++){
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	temp = A[j];
	A[j]=A[j-1];
	A[j-1] = temp;
	cnt++;
      }
    }
  }
  return cnt;
}
int main(){
  int A[100],N,i,j,cnt;
  scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    cnt = BubbleSort(A,N);

    for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n%d\n",cnt);
      return 0;
}

