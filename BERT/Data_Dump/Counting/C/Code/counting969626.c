#include<stdio.h>
#define N 2000005
int A[N],B[N],C[N];
int main(){
  int i,j,n,max=0;
  //int A[N];
  scanf("%d",&n);
  //int B[n],C[n];
  for(i=1 ; i<=n ; i++){
    scanf("%d",&A[i]);
    if(max<A[i]) max=A[i];
  }

  for(i=0 ; i<=max ; i++) C[i]=0;
  for(j=1 ; j<=n ; j++) C[A[j]]++;     //C[i]にはiの出現数を記録
  
  for(i=1 ; i<=max ; i++) C[i] = C[i] + C[i-1]; //C[i]にはi以下の出現数を記録

  for(j=n ; j>=1 ; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1 ; i<n ; i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);
  return 0;
  
}
