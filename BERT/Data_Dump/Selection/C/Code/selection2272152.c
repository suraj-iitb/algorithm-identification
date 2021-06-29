#include<stdio.h>
#define N 100

int main(){
  int i,j,n,minj,a,b = 0;
  int A[N];
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    scanf("%d",&A[i]);

  for(i = 0 ; i < n ; i++){
    minj = i;

    for(j = i ; j < n ; j++){
      
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(i != minj) b++;
    
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
  }

  for(i = 0 ; i < n ; i++){
    printf("%d",A[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n");
  
  printf("%d\n",b);

  return 0;
}
