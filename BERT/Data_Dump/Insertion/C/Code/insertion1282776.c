#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,n,v,j,k;
  int *A;

  scanf("%d", &n);
  A = (int *)malloc(n*sizeof(int));  //配列を確保

  for(i=0; i<n; i++) scanf("%d", A+i); //配列Aに値を入力

  for(i=0; i<n; i++){
    v = A[i];  //仮置き
    j = i-1;
    while(j>=0 && A[j]>v){ //iよりも前の要素と比較
      A[j+1] = A[j];       //一つ右にずらす
      j--;
    }
    A[j+1] = v;

    //結果出力
    for(k=0; k<n-1; k++) printf("%d ", A[k]);
    printf("%d\n", A[n-1]);
  }
  return 0;
}
