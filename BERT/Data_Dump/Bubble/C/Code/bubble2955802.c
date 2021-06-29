#include <stdio.h>
void bubble(int *a,int *b){
  int c;
  c=*a;
  *a=*b;
  *b=c;
}
int main(){
  int N,i,j,v,k;
  int A[1000];
  int flag;
  int count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  flag=1;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
      bubble(&A[j],&A[j-1]);
      flag=1;
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
