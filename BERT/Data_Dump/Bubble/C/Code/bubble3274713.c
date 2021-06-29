#include<stdio.h>
int main(){
  int N,i,j,temp,cout=0;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	cout++;
      }
    }
  }
  printf("%d",A[0]);
  for(i=1;i<N;i++){
    printf(" %d",A[i]);
  }
  printf("\n");
  printf("%d\n",cout);
  return 0;
}

