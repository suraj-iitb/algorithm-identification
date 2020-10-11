#include<stdio.h>

int n;

void CountingSort(int *A,int *B,int k){
  int i,C[k+1];

  for(i=0;i<=k;i++) C[i]=0;
  for(i=0;i<n;i++)  C[A[i]]++;

  //for(i=0;i<=k;i++) printf("%d ",C[i]); printf("\n");

  for(i=1;i<=k;i++) C[i]=C[i]+C[i-1];

  //for(i=0;i<=k;i++) printf("%d ",C[i]); printf("\n");

  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
    }
}

int main(){
  int i,k=0;
  scanf("%d",&n);
  int A[n],B[n];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<A[i]) k=A[i];
  }
  
  CountingSort(A,B,k);

  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",B[i]);
  }

  printf("\n");
  
  return 0;
}



