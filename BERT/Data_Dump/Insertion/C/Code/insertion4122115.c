#include<stdio.h>

int main(){
  int N,i,j,c,key;
  int A[1000];
  scanf("%d",&N);
  if((1<=N)&&(N<=100)){
  for(i=0;i<N;i++){
  scanf("%d",&A[i]);
}
}
  for(i=0;i<N-1;i++)
  printf("%d ",A[i]);

  printf("%d",A[i]);

  printf("\n");
  
  for(j=1;j<N;j++){
  key=A[j];
  i=j-1;
  while((i>=0)&&(A[i]>key)){
  A[i+1]=A[i];
  i--;
}
  A[i+1]=key;
  for(c=0;c<N-1;c++)
  printf("%d ",A[c]);
  printf("%d",A[c]);
  printf("\n");
}
  return 0;
}

