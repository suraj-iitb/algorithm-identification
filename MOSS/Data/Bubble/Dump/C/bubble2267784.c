#include<stdio.h>

int main(){
  int i, j, n, p, count=0;
  int A[100];

  scanf("%d",&n);

  for(i=0 ; i<n ; i++) scanf("%d",&A[i]);

  for(i=0 ; i<n ; i++){
    for(j=n-1 ; j>i ; j--){
      if(A[j] < A[j-1]){
	p = A[j];
	A[j] = A[j-1];
	A[j-1] = p;
	count++;
      }
    }
  }
  for(i=0 ; i<n-1 ; i++) printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],count);

  return 0;
}
