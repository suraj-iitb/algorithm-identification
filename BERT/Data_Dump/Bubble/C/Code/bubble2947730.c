#include<stdio.h>
void Swap(int *x,int *y){
  int v;
  v = *x;
  *x = *y;
  *y = v;
}
int main()
{
  int N;
  int i,j,v,k;
  int A[100];
  int flag,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  flag = 1;
  while(flag){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	Swap(&A[j],&A[j-1]);
	flag = 1;
	count++;
      }
    }
  }   
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}


