#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10001

int n;

void CountingSort(unsigned short int *,unsigned short int *,int);

int main(){

  unsigned short int *A,*B;
  int i,j,k=0;
  int maxim=-1;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
   
  for(i=1;i<=n;i++){
    scanf("%hd",&A[i]);
    if(A[i]>maxim){
      maxim=A[i];
    }
  }

  k=maxim+1;

  CountingSort(A,B,k);

  for(j=1;j<=n;j++){
    printf("%d",B[j]);
    if(j==n) printf("\n");
    else printf(" ");
  }

  return 0;
  
}

void CountingSort(unsigned short int *A,unsigned short int *B,int k){

  int i,j;
  int C[VMAX+1];

  for(i=0;i<=k;i++){
    C[i]=0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i]+C[i-1];
  }
  
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
}

