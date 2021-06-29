#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, *A;
  int i, j, flag=0, minj, cnt=0, tmp;
  
  scanf("%d",&n);
  A = (int*)malloc( sizeof(int)*n );
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
  
  for(i=0; i<n; i++){
    flag = 0;
    minj = i;
    for(j=i; j<n; j++){
      if( A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }
    tmp     = A[i];
    A[i]    = A[minj];
    A[minj] = tmp;
    if(flag == 1) cnt++;
  }
  
  for(i=0; i<n-1; i++)
    printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",cnt);
  
  return 0;
}
