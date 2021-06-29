#include<stdio.h>
int N;

int bubble(int A[]){
  int flag = 1;
  int i,j,tmp;
  int count = 0;
  for(i=0;i<N;i++){
    flag = 0;
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] =tmp;
        count++;
      }
    }
  }
  return count;
}
int main(){
  int A[100],i;
  int sw;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  sw = bubble(A);
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",sw);

  return 0;
}
