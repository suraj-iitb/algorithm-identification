#include<stdio.h>
void bubbleSort(int *,int);
int cnt=0;
int main(){
  int N;
  int A[101];
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,N);
  printf("%d\n",cnt);
  return 0;
}
void bubbleSort(int A[],int N){
  int flag=1;
  int j,tmp;
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	cnt++;
      }
    }
  }
  for(j=0;j<N;j++){
    printf("%d",A[j]);
    if(j!=N-1) printf(" ");
  }
  printf("\n");
}
      

