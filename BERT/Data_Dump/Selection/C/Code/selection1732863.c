#include<stdio.h>

int main(){
  int i, j, N, minj, temp, A[100], count=0;

  scanf("%d", &N);
  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj])minj = j;
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj)count++;
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i], count);
  return 0;
}
