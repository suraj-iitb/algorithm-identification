#include <stdio.h>
#define MAX 2000001

int A[MAX];
int B[MAX];
int C[MAX];

int n;

void CountingSort(int A[], int B[], int k){
  int i, j;

  for(i=0;i<=k;i++)C[i] = 0;
  
  for(j=1;j<=n;j++)C[A[j]]++;
  
  for(i=1;i<=k;i++)C[i] = C[i] + C[i - 1];
      
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
  int i;
  int k=0;

  scanf("%d",&n); 
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    
    if(k < A[i])k=A[i];
  }
  

  CountingSort(A, B, k);

  for(i=1;i<=n;i++){
    printf("%d", B[i]);
    if(i==n)printf("\n");
    else printf(" ");
  }
  return 0;
}

