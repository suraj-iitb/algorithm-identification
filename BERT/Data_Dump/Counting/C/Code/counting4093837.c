#include <stdio.h>
#define N 2000001
void CountingSort(short *,short *,int,int);

int main(){
  int max=-1,n,i;
  short A[N],B[N];
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%hd",&A[i]);
    if(max<A[i]) max=A[i];
  }
  CountingSort(A,B,max,n);
  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;  
}
  
void CountingSort(short A[],short B[],int k,int n){
  int C[k+1],i,j;
  for (i = 0;i<=k;i++) C[i] = 0;
  
  /* C[i] に i の出現数を記録する */
  for (j = 1;j<=n;j++) C[A[j]]++;
  
  /* C[i] に i 以下の数の出現数を記録する*/
  for (i = 1;i<= k;i++) C[i] = C[i] + C[i-1];
  
  for (j = n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

