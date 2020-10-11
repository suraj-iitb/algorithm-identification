#include<stdio.h>
#include<stdlib.h>

#define M 2000000


int n,A[M],B[M+1],C[M];


void counting(int max){

  int i, j;

  for(j=0;j<n;j++) C[A[j]] = C[A[j]] + 1;


  for(i=1;i<=max;i++) C[i] = C[i] + C[i-1];


  for(j=n-1;j>=0;j--){
        
    B[C[A[j]]] = A[j];
    C[A[j]]--;

  }


  for(i=1;i<=n;i++){
    if(i==n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
    
  }
}
  
  

int main(){


  int i,j,k;


  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  k = A[0];
  for(i=1;i<n;i++){
    if(k<A[i]) k =A[i];
  }


  counting(k);

  return 0;
}

