#include<stdio.h>

static const int N = 1000;
void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int n){
  int i,j,v;
  for(i=2;i<=n;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    trace(A,n);
  }
}
int main(){
  int i,j,n;
  int A[N+1];

  scanf("%d",&n);
  for(i=1;i<=n;i++) scanf("%d",&A[i]);

  trace(A,n);
  insertionSort(A,n);
  
  return 0;
}
