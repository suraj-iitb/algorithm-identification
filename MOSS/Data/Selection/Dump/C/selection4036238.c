#include <stdio.h>

int slectionSort(int A[],int N){
  int i,j,t,s =0,mj;
  for(i=0;i<N-1;i++){
    mj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[mj])mj = j;
    }
    t = A[i];
    A[i] = A[mj];
    A[mj]=t;
    if(i!=mj)s++;
  }
  return s;
}
int main(){
  int A[100],N,i,s;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  s=slectionSort(A,N);

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",s);

  return 0;
}
    

