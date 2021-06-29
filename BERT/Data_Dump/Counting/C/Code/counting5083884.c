#include<stdio.h>

void Countingsort(int *,int *,int);

int n,C[10001],k,A[2000001],B[2000001];

int main(){
  int i;
  
  scanf("%d",&n);       /*入力*/
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k < A[i])k = A[i];
  }

  Countingsort(A,B,k);

  for(i=1;i<=n;i++){     /*出力*/
    printf("%d",B[i]);
    if(i != n)printf(" ");
    else printf("\n");
  }
  return 0;
}

void Countingsort(int *A,int *B,int k){
  int i,j;
  for(i=0;i<=k;i++)C[i]=0;
  
  for(j=0;j<n;j++)C[A[j]]++;
  
  for(i=1;i<=k;i++)C[i] = C[i] + C[i-1];
  
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
    

