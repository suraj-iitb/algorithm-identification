#include<stdio.h>
int main(){
  int A[100],N,i,j,k,l,temp,count=0,minj;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  /*selection sort 0-origin*/
  for(j=0;j<N-1;j++){
    minj=j;
    for(k=j;k<N;k++){
      if(A[k]<A[minj]) minj=k;
    }
    temp=A[j];
    A[j]=A[minj];
    A[minj]=temp;
    if(j!=minj) count++;
  }
  for(l=0;l<N-1;l++)printf("%d ",A[l]); printf("%d",A[N-1]);
  printf("\n%d\n",count);
  return 0;
}

