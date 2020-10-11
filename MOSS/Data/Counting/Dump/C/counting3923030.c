#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void countingsort(unsigned short *A,unsigned short *B,int *C,int k)
{
  int i,j;
  int max=0;
  for(i=0;i<k;i++){//CにAの各要素の出現回数を格納
      C[A[i]]++;
      if(max<A[i]) max=A[i];
  }
  for(i=1;i<max+1;i++) C[i] = C[i-1] + C[i];//累積和を計算
  for(i=k-1;i>-1;i--) {//BにAのlastから理想の位置に格納
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<k+1;i++){
      if(i != 1) printf(" ");
      printf("%d",B[i]);
  }
  printf("\n");
}

int main(){
  unsigned short *A, *B;
  int C[VMAX+1]={};
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++) scanf("%hd",&A[i]);
    
  countingsort(A,B,C,n);

  free(A);
  free(B);
  return 0;
}
