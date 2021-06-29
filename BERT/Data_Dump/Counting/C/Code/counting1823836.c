#include<stdio.h>
#include<stdlib.h>
 
 
int A[2000002],B[2000002];
int C[10001];
int n;
void Counting_Sort(int A[], int B[], int n);
 
int main(){
  int i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
 
    scanf("%d",&A[i]);
 
}
  Counting_Sort(A, B, 10000);
 
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
}
  printf("%d\n",B[n]);
 
  return 0;
}
 
 
void Counting_Sort(int A[],int B[],int k){
  int i,j;
  for(i=0;i<=k;i++){
    C[i]=0;
  }
 
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
 for(i=1;i<=k;i++){
    C[i] =C[i]+ C[i-1];
  }
  
 for(j=n;j>=0;j--){
   B[C[A[j]]] = A[j];
   C[A[j]] = C[A[j]] -1;
 }
 
 return;
}
