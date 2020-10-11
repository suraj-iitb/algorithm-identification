#include<stdio.h>
#include<stdlib.h>

int n;

int C[100000];

void CountingSort(int,short*,short*);

int main(){
  int i,k=0;
  unsigned short *A, *B;
  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<=A[i]){
      k=A[i];
    }
  }

  CountingSort(k,A,B);
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
}


void CountingSort(int k,short* A,short* B){
  int i,j;
  for(i=0;i<=k;i++)C[i]=0;

  for(j=0;j<n;j++){
    C[A[j]]++;
    //printf("%d %d\n",C[A[j]],A[j]);
  }
  
  
  for(i=1;i<=k;i++)C[i]=C[i]+C[i-1];

  
  for(j=n;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  
}

