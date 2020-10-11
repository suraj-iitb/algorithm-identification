#include<stdio.h>

int main(){
  int i,minj,j,N,count,b,s;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }
  count=0;
  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
    if(i!=minj)
      count++;
    b=A[i];
    A[i]=A[minj];
    A[minj]=b;
  }
  for(s=0;s<=N-1;s++){
    if(s<N-1)
      printf("%d ",A[s]);
    else printf("%d\n",A[s]);
  }
  printf("%d\n",count);
  
  return 0;
}
  

