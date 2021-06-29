#include<stdio.h>
#include<stdlib.h>

#define n_MAX 2000000
#define A_MAX 10000

int n;

void CountingSort(int *, int *, int);

int main(){
  int k=0;
  int *A, *B;
  int i;
  
  scanf("%d",&n);
  if(n<1 || n_MAX<n) exit(1);

  A=(int *)malloc((n+1)*sizeof(int));
  B=(int *)malloc((n+1)*sizeof(int));

  for(i=1; i<=n; i++){
    scanf("%d", &A[i]);
    if(A[i]<0 || A_MAX<A[i]) exit(2);
    if(k<A[i])k=A[i];
  }

  CountingSort(A,B,k);

  for(i=1; i<=n; i++){
    printf("%d",B[i]);
    if(i!=n)printf(" ");
  }
  printf("\n");

  return 0;
}

void CountingSort(int *A, int *B, int k){
  int i,j;
  int C[k+1];

  for(i=0; i<=k; i++){
    C[i]=0;
  }

  for(j=1; j<=n; j++){
    C[A[j]]++;
    //printf("A[%d] %d   C[A[%d]=%d] %d\n",j,A[j],j,A[j],C[A[j]]);
  }

  for(i=1; i<=k; i++){
    C[i]+=C[i-1];  //C[k]は合計の個数になる
    //printf("C[%d] %d\n",i,C[i]);
  }

  for(j=n; 0<j; j--){
    B[C[A[j]]]=A[j];
    //printf("B[C[A[%d]]=%d]=%d\n",j,C[A[j]],B[C[A[j]]]);
    C[A[j]]--;
  }

}

