#include <stdio.h>
#define MAX 2000000
#define VMAX 10000


void countingsort(int*,int*,int);
  void countingsort(int *A,int* B,int n){
  int i,j,C[VMAX+1];
  for(i=0;i<=VMAX;i++) C[i]=0;
  for(j=1;j<=n;j++) C[A[j]]++;
  for(i=1;i<=VMAX;i++) C[i] = C[i]+C[i-1];
  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
  int i,n;
  
  scanf("%d",&n);
  int A[n+1],B[n+1];
  for(i=1;i<n+1;i++) scanf("%d",&A[i]);
  countingsort(A,B,n);
  
  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);
  return 0;
}
    
  
  
    

