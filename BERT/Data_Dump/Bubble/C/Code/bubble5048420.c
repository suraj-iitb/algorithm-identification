#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, *A;
  int i, j, tmp, cnt=0;

  scanf("%d",&n);
  A = (int*)malloc( sizeof(int)*n );
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);

  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if( A[j] < A[j-1] ){
	tmp    =  A[j];
	A[j]   =  A[j-1];
	A[j-1] =  tmp;
	cnt++;
      }
    }
  }
  for(i=0; i<n-1; i++)
    printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",cnt);
  return 0;
}
