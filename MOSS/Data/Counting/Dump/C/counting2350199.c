#include<stdio.h>
#include<stdlib.h>

void CountingSort(int);
		  
int A[2000000];
int B[2000000]={};

int main(){
  int n, i;

  scanf("%d",&n);
  if( n<1 || 2000000<n ) exit(0);

  for( i=0 ; i<n ; i++ ){
    scanf("%d",&A[i]);
    if( A[i]<0 || 10000<A[i] ) exit(1);
  }

  CountingSort(n);
  
  for( i=0 ; i<n ; i++ ){
    if( i==n-1 ){
      printf("%d\n",B[i]);
    }
    else{
      printf("%d ",B[i]);
    }
  }
  
  return 0;
}

void CountingSort(int n){
  int i, j;
  int C[10000]={};

  for( j=0 ; j<n ; j++ ){
    C[A[j]]++;
  }
  
  for( i=0 ; i<10000 ; i++ ){
    C[i] = C[i] + C[i-1];
  }

  for( j=n-1 ; j>=0 ; j-- ){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}
