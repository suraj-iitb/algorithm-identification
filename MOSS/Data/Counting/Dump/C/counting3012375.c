#include<stdio.h>

void Sort(int*, int*, int);

int main(){
  int i;
  int n;

  scanf("%d",&n);

  int A[n],B[n];

  for(i=0;i<n;i++){
    scanf(" %d",&A[i]);
  }

  Sort(A,B,n);

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);

  return 0;
}

void Sort(int *A,int *B,int k){
  int i,j,max;
  
  max=A[0];
  for(i=1;i<k;i++){
    if(max<A[i])max=A[i];
  }

  int C[max+1];
  for(i=0;i<=max;i++){
    C[i]=0;
  }

  for(j=0;j<k;j++){
    C[A[j]]++;
  }

  for(i=1;i<=max;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=k-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
    
  }

}

