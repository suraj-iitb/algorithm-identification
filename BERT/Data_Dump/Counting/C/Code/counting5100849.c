#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(short *,short *,int);
int C[VMAX+1],n,i,j;

int main(){
  unsigned short *A,*B;
  scanf("%d",&n);
  A = malloc(sizeof(short) * n+1);
  B = malloc(sizeof(short) * n+1);
  for(i = 1;i <= n;i++)scanf("%d",&A[i]);
  CountingSort(A,B,VMAX);
  for(i = 1;i <= n;i++){
    if(i == n)printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }
  return 0;
}

void CountingSort(short A[],short B[],int k){
  for(i = 0;i <= k;i++)C[i] = 0;
  for(j = 1;j <= n;j++){
    C[A[j]]++;
  }
  for(i = 1;i <= k;i++)C[i] = C[i] + C[i-1];
  for(j = n;j >= 1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
