/* 1つの最小値を選択していく*/
#include<stdio.h>
#define NUM 100

void selectionSort(int *,int);

int main(){
  int i,a[NUM],n,cnt;

  scanf("%d",&n);
  for(i=0;i<n; i++){
    scanf("%d",&a[i]);
  }
 selectionSort(a,n);
  return 0;
}

void selectionSort(int *A,int N){
  int i,j,minj,v,cnt=0;
  for(i=0; i<=N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(A[j] < A[minj])
        minj = j;
    }
    if(A[i] != A[minj]){
      v = A[i];
      A[i] = A[minj];
      A[minj] = v;
      cnt++;
    }

  }
   for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
    printf("%d\n",A[N-1]);
    printf("%d\n",cnt);
}


