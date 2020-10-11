#include<stdio.h>
#include<stdlib.h>
 
#define Array_MAX 10000
 
void countingSort(short *A,short *B,int n){
  int i,j;
  int C[Array_MAX+1];
 
  for(i=0;i<=Array_MAX;i++)
    C[i] = 0;
  for(j=1;j<=n;j++)
    C[A[j]]++;
  for(i=1;i<=Array_MAX;i++)
    C[i] = C[i] + C[i-1];
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
 
int main(){
  unsigned short *A, *B;
  int n,i;
 
  scanf("%d",&n);
   
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
 
  for(i=1;i<=n;i++)
    scanf("%hd",&A[i]);
   
  countingSort(A,B,n);
 
  for(i=1;i<n;i++)
    printf("%hd ",B[i]);
  printf("%hd\n",B[n]);
   
  free(A);
  free(B);
  return 0;
}
     
  
