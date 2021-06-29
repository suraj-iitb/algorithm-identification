#include <stdio.h>

void insertSort(int A[],int N){
  int i,j,v;
  for(i=1;i<N;i++){
    j=i-1;
    v=A[i];
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    trace(A,N);
  }
}

void trace(int A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

int main(void){
  int n,i;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  trace(a,n);
  insertSort(a,n);
  return 0;
}
