#include<stdio.h>

#define MAX 2000001
#define VMAX 10000

int A[MAX],C[VMAX+1],B[MAX];

void countingSort(int *A, int k) {
  
  int i,j;

  // 初期化
  for(i=0;i<VMAX;i++) {
    C[i] = 0;
  }

  // 出現数の記録
  for(j=1;j<=k;j++) {
    C[A[j]]++;
  }
  
  // トータルのカウント
  for(i=1;i<VMAX;i++) {
    C[i] += C[i-1];
  }
  
  for(j=1;j<=k;j++) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
   
  }

  for(i=1;i<k;i++) {
    printf("%d ",B[i]);
  }
  printf("%d\n",B[k]);

}



int main(char args[]){

  int i,n;
  
  scanf("%d",&n);
  
  for(i=1;i<=n;i++) {
    scanf("%d",&A[i]);
  }

  countingSort(A,n);

  
  return 0;
}
