#include<stdio.h>

int bubbleSort(int A[], int N);

int main(){
  int N,i,cnt;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  cnt=bubbleSort(A,N);

  for(i=0;i<N;i++){
    if(i>0 && i<N) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

int bubbleSort(int A[],int N){
  int flag=1,j,a,cnt=0;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	flag=1;
	cnt++;
      }
    }
  }
  return cnt;
}
