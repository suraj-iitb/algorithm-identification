#include<stdio.h>
#define N 2000001
int n,B[N];

void Counting_Sort(int[],int);

int main(){

  int A[N],i,k=0;

  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    scanf("%d",&A[i]);
    if(A[i] > k) k = A[i];
  }

  Counting_Sort(A,k+1);

  for(i = 1; i < n; i++) printf("%d ",B[i]);
  printf("%d\n",B[i]);

  return 0;
}

void Counting_Sort(int A[],int k){

  int i,j,C[k];

  for(i = 0; i < k; i++) C[i] = 0;
  for(j = 1;j <= n; j++) C[A[j]]++;
  for(i = 1; i < k; i++) C[i] = C[i] + C[i - 1];
  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
