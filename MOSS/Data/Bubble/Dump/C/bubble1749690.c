#include<stdio.h>
void BubbleSort(int *,int );
int main(){
  int A[100];
  int  N;
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  BubbleSort(A,N);
  return 0;
}

void BubbleSort(int *A,int N){
  int j,flag=1,temp,cnt=0;
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	cnt++;
	flag=1;
      }
    }
  }
  for(j=0;j<N;j++){
    if(j==N-1)printf("%d\n",A[j]);
    else printf("%d ",A[j]);
}
printf("%d\n",cnt);
}
