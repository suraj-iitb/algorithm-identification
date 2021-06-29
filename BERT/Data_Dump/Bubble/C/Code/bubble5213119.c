#include<stdio.h>
#include<stdbool.h>
int bubblesort(int A[],int N){
  int sw=0;
  bool flag=1;
  for(int i=0;flag;i++){
    flag=0;
    for(int j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	int tmp;
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	sw++;
      }
    }
  }
  return sw;
}
int main(){
  int A[100],N,sw;
  scanf("%d",&N);
  for(int i=0;i<N;i++) scanf("%d",&A[i]);
  sw=bubblesort(A,N);
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);
  return 0;
}

