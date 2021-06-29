#include <stdio.h>
static int c = 0;
void s(int *a,int *b){
  int i=*a;*a=*b;*b=i;c++;
}
void sS(int *A, int a){
  int i,j;
  for(i=0;i<a;i++){
    int m=i;
    for(j=i;j<a;j++)
      if(A[j]<A[m])
        m=j;
    if(A[i]!=A[m])
      s(&A[i],&A[m]);
  }
}
int main(void){
  int N,n,A[101];
  scanf("%d\n",&N);
  for(n=0;n<N;n++){
    int i;
    scanf("%d", &i); A[n] = i;
  }
  sS(A,N);
  for(n=0;n<N-1;n++)
    printf("%d ",A[n]);
  printf("%d\n",A[N-1]);
  printf("%d\n",c);
  return 0;
}
