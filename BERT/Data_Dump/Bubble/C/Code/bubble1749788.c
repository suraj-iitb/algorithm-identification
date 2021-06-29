#include <stdio.h>
#define N 100
int bubblesort(int*,int);

int main(){
  int i,n,c;
  int A[N];

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);
 
  c = bubblesort(A,n);

  for(i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",c);  
  return 0;
}

int bubblesort(int A[],int n) {
  
  int c = 0,tmp,i,j,flag = 1;
  
  while (flag){
    flag = 0;
    for(j = n-1; j >= 1; j--){
      if(A[j] < A[j-1]) 
	{
	  tmp = A[j-1];
	  A[j-1] = A[j];
	  A[j] = tmp; 
	  c++;
      flag = 1; 
	}
    }
  } 
  return c; 
}
