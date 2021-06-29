#include<stdio.h>
int main(){
  int A[100];
  int i,j,flag,a,b;
  int N,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  i=0;
  while(flag==1){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	flag=1;
	count++;
      }
      i++;
    }
  }
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}
