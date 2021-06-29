#include<stdio.h>
#include<stdlib.h>
 
#define NMAX 2000001
 
int n;
int A[NMAX],B[NMAX],C[NMAX];
 
void CountingSort(int k);
 
int main(void){
  int i,k;
 
  scanf("%d",&n);
 
  k=0;
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(k <= A[i]) k=A[i];
  }
 
  CountingSort(k);
 
  for(i=0; i<n; i++){
    if(i==n-1) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
    }
 
  return 0;
}
 
void CountingSort(int k){
  int i,j;
 
  for(i=0; i<=k; i++) C[i]=0;
 
  for(j=0; j<n; j++)C[A[j]]=C[A[j]]+1;
 
  for(i=1; i<=k; i++) C[i]+=C[i-1];
 
  for(j=n-1; j>=0; j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
 
}
