#include <stdio.h>
#include <stdlib.h> 
#define MAX 2000000
#define NMAX 10000

void Countingsort(int [],int *,int);

int main(void){
  
  int *A = malloc(sizeof (int)*MAX);
  int *B = malloc(sizeof (int)*MAX);
  int n;
  int i;
  
  scanf("%d",&n);
  

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  
  Countingsort(A,B,n);


  for(i=0;i<n-1;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[i]);

  free(A);
  free(B);

  return 0;
}


void Countingsort(int A[],int *B,int k){

  int i,j;
  int C[NMAX+1];

  for(i=0;i<NMAX;i++)
    C[i] = 0;

  for(j=0;j<k;j++)
    C[A[j]]++;
  /* C[i]にはiの出現数が記録されている*/

  for(i = 1;i<NMAX;i++)
    C[i] = C[i] + C[i-1];
  /* C[i]にはi以下の数の出現数が記録されている*/

  for(j=k-1;j>=0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}
