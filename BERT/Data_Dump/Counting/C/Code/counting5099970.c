#include <stdio.h>

#define MAX 2000001
#define VMAX 10000

void Counting(int A[],int size,int data_size){
  int i, j;
  int B[data_size];
  int C[size];

  for (j=0;j<data_size; j++) B[j] = 0;
  for (i=0;i<size; i++ ) B[A[i]]++;

  for (j=1;j<data_size;j++) B[j]+=B[j-1];

  for (i=size-1;i>=0;i--) {
    C[B[A[i]]-1] = A[i];
    B[A[i]]--;
  }

  for(i=0;i<size;i++) A[i]=C[i];
}

int main(){
  int A[MAX];
  int n, i, j,max=0;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(max<A[i]){
      max=A[i];
    }
  }
  Counting(A, n, max+1);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

  return 0;
}


