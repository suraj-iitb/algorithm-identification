#include <stdio.h>

void CountingSort(int[], int[], int);

int n, A[2000001], B[2000001];

int main(){
  int i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  CountingSort(A, B, 10000);
  
  for (i=1;i<=n;i++){
    if (i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}


void CountingSort(int A[], int B[], int k){
  int i, j;
  int C[k+1];
  for(i=0;i<=k;i++) C[i]=0;
  
  /* C[i] ??? i ???????????°????¨?????????? */
  for(j=0;j<n;j++) C[A[j]]++;
  
  /* C[i] ??? i ??\????????°???????????°????¨??????????*/
  for(i=1;i<=k;i++) C[i] = C[i] + C[i-1];
  
  for(j=n;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
