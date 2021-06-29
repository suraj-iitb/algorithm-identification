#include<stdio.h>
int n;
int A[2000001];
int B[2000001];
void CountingSort(int *,int *,int k);
int main(){
  int i;
  int mx=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&A[i]);
    if(mx<A[i]) mx=A[i];
  }
  CountingSort(A,B,mx);
  
  return 0;
}

void CountingSort(int A[],int B[],int k){
  int C[10001];
  int i,j;
  for(i=0;i<=k;i++) C[i]=0;
  for(i=0;i<n;i++) C[A[i]]++;
  for(i=1;i<=k;i++) C[i]+=C[i-1];
  /*
  for(i=0;i<=k;i++){
    printf("%d\n",C[i]);
  }
  */
  for(j=n-1;j>=0;j--) {
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }

  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
}

