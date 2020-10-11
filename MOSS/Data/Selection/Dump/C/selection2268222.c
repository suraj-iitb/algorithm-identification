#include<stdio.h>
void trace(int A[],int N){
  int i;
 
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void swap(int *x,int *y)
{
  int a;
  a=*x;
  *x=*y;
  *y=a;
}

int main(){
  int A[100];
  int i,j,n,N,minj;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
 
  for(i=0,N=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]) minj=j;
      
    }
      swap(&A[i],&A[minj]);
      if(i!=minj) N++;
  }
  trace(A,n);
  printf("%d\n",N);
  return 0;
}
