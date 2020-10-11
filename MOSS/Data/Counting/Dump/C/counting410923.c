#include<stdio.h>
int A[2000000];
int B[2000000];
void countingSort(k,n){
  int i,j,C[k+1];
  for (i = 0;i<=k;i++){
    C[i] = 0;
	   }
  for( i = 0;i < n;i++){
    C[A[i]] = C[A[i]]+1;
  }
    /* C[i]にはiの出現数が記録されている*/
  for( i = 1; i <= k; i++){
    C[i] = C[i] + C[i-1];
       }
    /* C[i]にはi以下の数の出現数が記録されている*/
  for( i = n ; i >= 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]] = C[A[i]]-1;
  }
}
int main(){
  int i,j,k,n;
  k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }
  countingSort(k,n);
  for(i=1;i<=n;i++){
    if(i!=1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}
