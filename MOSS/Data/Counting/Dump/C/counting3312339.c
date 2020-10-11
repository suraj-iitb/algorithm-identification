#include <stdio.h>

#define MAX 2000001
#define VMAX 10000

void countingsort(int,int);
int A[MAX],B[MAX],C[VMAX+1];
int n,i,k=0;


int main(){

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  countingsort(VMAX,n);

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d",B[n]);
  printf("\n");


return 0;
}

void countingsort(int k,int n){
  int j;

  for(i=0;i<=k;i++){
    C[i] = 0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

