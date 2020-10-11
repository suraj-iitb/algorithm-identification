#include<stdio.h>

int main(){
  //counter
  int i,j;

  //input
  int n;
  scanf("%2000000d",&n);
  
  int A[n];
  int k=0;  // TODO serching "k"
  for(i=0;i<n;i++){
    scanf("%10000d",&A[i]);
    if(A[i]>k){
      k = A[i];
  }
  }

  
  //Counting Sort

  int C[k+1];
  for(i=0;i<k+1;i++){
    C[i] = 0;
  }
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=1;i<k+1;i++){
    C[i] = C[i] + C[i-1];
  }
    int B[n];
    for(j=(n-1);j>=0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
    }

  //output
  for(i=0;i<n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n-1]);
  


    return 0;
}

