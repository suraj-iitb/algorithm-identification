#include<stdio.h>

void countingsort(int *,int *,int);

int main(){
  int n,i;
  scanf("%d",&n);
  int A[n],B[n];
  for(i=0;i<n;i++){
    scanf("%d",A+i);
  }
  
  countingsort(A,B,n);

  printf("%d",B[0]);

  for(i=1;i<n;i++) printf(" %d",B[i]);
  printf("\n");

  return 0;
}

void countingsort(int *A,int *B,int n){
  int C[10000],i;

  for(i=0;i<10000;i++) C[i]=0;

  for(i=0;i<n;i++) B[i]=0;

  for(i=0;i<n;i++) C[A[i]]++;

  for(i=1;i<10000;i++) C[i]=C[i]+C[i-1];
  
  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

