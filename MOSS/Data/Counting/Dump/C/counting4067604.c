#include <stdio.h>
#define na 2000000 //int main()の中でA[2000000]2百万個を用意できないので外に出す

void CountingSort(int*, int*, int);
int B[na];
int main(){

  int n, A[na], C[10000], i, k;

  scanf("%d", &n);
  for(i=0; i<10000; i++){
    C[i]=0;}
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
    C[ A[i] ]++; //配列A[i]=0とするとC[0]の中身を+1する
  }

  //累積和を入れたC'を作る
  for(i=1; i<10000; i++){//以降はC'しか使わないのでC[]に代入して使う
    C[i]=C[i]+C[i-1];
  }//C[0]はC[0]のままなので飛す
  
  CountingSort(A, C, n);

  for(i=1; i<=n-1; i++) printf("%d ", B[i]);
  printf("%d\n", B[n]);

  return 0;
}

void CountingSort(int A[], int C[], int n){

  int i;
  
  for(i=0; i<=n; i++){
    B[ C[ A[n-i] ] ] = A[n-i];
    C[ A[n-i] ]--;

  }

}



