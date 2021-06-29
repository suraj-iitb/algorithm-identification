#include<stdio.h>
#define N 100
int main(){
  int A[N];
  int n,i,j,minj,x,c;

  scanf("%d", &n);
  if(n<1 || n>100) return 0;
  for(i = 0 ; i < n ; i++) scanf("%d", &A[i]);
  c = 0;
  
  for(i = 0 ; i <= n-1 ; i++){
    minj = i;
    for(j = i ; j <= n-1 ; j++){    
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(i != minj) {
	x = A[i];
	A[i] = A[minj];
	A[minj] = x;
	c++;
    }
  }

  for(i = 0 ; i < n-1 ; i++) printf("%d ", A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",c);
  return 0;
}

