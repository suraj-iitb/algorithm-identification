#include <stdio.h>

#define N 100

void trace(int A[], int n){
  int i;
  for (i=0;i < n;i++){
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int A[N];
  int n=0;
  int i,j;
  int count=0;
  
  scanf("%d",&n);
  
  if(n > 100 || n < 0){
    return 0;
  }
  
  for(i=0;i < n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i < n;i++){
    for(j=n-1;j > i;j--){
      if(A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	count++;
      }
    }
  }
  trace(A,n);
  printf("%d\n",count);
  
  return 0;
}
