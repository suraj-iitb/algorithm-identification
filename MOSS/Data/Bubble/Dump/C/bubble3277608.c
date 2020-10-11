#include<stdio.h>
#define N 100

int main(){
  int A[N];
  int n,flag,i,j,x,c;
   
  scanf("%d", &n);
  for(j = 0 ; j < n ; j++) scanf("%d", &A[j]);
  
  flag = 1;
  i = 0;
  c = 0;
  
  while(flag){
    flag = 0;
    for(j = n-1 ; j >= i+1 ; j--){
      if(A[j] < A[j-1]){
	x = A[j];
	A[j] = A[j-1];
	A[j-1] = x;
	flag = 1;
	c++;
      }      
    }
    i++;
    
  }
  for(j = 0 ; j < n-1 ; j++) printf("%d ",A[j]);
  printf("%d",A[n-1]);
  printf("\n%d\n",c);
  
  return 0;
}

