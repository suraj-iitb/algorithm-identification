#include <stdio.h>

static int c = 0;

void s(int *a,int *b){
  int i=*a;*a=*b;*b=i;
}

void bS(int *A, int a){
  int i,j;
  for(i=0;i<a;i++)
    for(j=a-1;j>i;j--)
      if(A[j]<A[j-1]) {
        s(&A[j],&A[j-1]); c++;}
}

int main(void){
  int N,n;
  int A[101];
  scanf("%d\n",&N);
  for(n=0;n<N;n++){
    int i;
    scanf("%d", &i); A[n] = i;
  }
  bS(A,N);
  for(n=0;n<N-1;n++)
    printf("%d ",A[n]);
  printf("%d\n",A[N-1]);
  printf("%d\n",c);
  return 0;
}
