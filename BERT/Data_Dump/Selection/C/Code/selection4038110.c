#include<stdio.h>

int main(){
  int N,i,j,minj,tmp,data,A[100],trade=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  for(i=0;i<N-1;i++){
    for(minj=j=i+1;j<N;j++){
      if (A[minj] > A[j]) minj = j;
    }
    if(A[i] > A[minj]){
      trade++;
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
    } 
  }
  for(i=0;i<N;i++){
    if(i==N-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",trade);
  return 0;
}
