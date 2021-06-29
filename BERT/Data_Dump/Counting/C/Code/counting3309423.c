#include<stdio.h>
#include<stdlib.h>
#define M 10000

int C[M + 1];
int n;

void CountingSort(unsigned short *A, unsigned short *B, int k){
  int i,j,max = 0;

  for(i = 0; i <= n; i++){
    if(A[i] > max) max = A[i];
  }
  k = max;
  for(i = 0; i <= k; i++){
    C[i] = 0;
  }
  
  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }

  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i - 1];
  }

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

}



int main(){
  int i;
  unsigned short *A, *B;
  
  scanf("%d",&n);
  
  A = malloc(sizeof(short)*n + 1);
  B = malloc(sizeof(short)*n + 1);

  for(i = 1; i <= n; i++){
    scanf("%hd",&A[i]);
  }

  CountingSort(A,B,n);
  for(i = 1; i <= n; i++){
    if(i == n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }
  return 0;
}

