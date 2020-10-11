#include <stdio.h>
#define N 100
int selectionSort(int*,int);

int main(){
  int i,n,c;
  int A[N];

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);
 
  c = selectionSort(A,n);

  for(i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",c);  
  return 0;
}

int selectionSort(int A[],int n) {
  
  int c = 0,tmp,i,j,minj;

  for(i = 0; i <= n-1; i++){
    minj =i;
    for(j = i; j <= n-1; j++){
      if (A[j] < A[minj])
	minj = j;
    }
    if(i!=minj) {
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      c++;
    }
    
  }
  return c;
}
