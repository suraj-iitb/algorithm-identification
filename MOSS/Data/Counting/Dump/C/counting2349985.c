#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define Max 10000
int n;
void count(short *, short *, int);
int main()
{
  unsigned short *A,*B;
  int i,k=Max;
  
  scanf("%d",&n);
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  
  for(i=0; i<n; i++){
    scanf("%hd",&A[i+1]);
  }

  count(A,B,k);

  for(i=1; i<=n; i++){
    if(i>1) printf(" ");
    printf("%hu",B[i]);
  }
  
  printf("\n");
  
  return 0;
  
}

void count(short *A,short *B,int k)
{
  int C[Max+1];
  int i,j;

  for(i=0; i<=k; i++){
    C[i] = 0;
  }

  for(j=1; j<=n; j++){
    C[A[j]]++;
  }

  for(i=1; i<=k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

}
  
  
