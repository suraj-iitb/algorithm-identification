#include <stdio.h>

int main(){

int A[100];
  int i,j,minj,swap,n,count=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    }

  for(i=0; i<=n-1; i++){
    minj=i;
    for(j=i; j<=n-1; j++){
      if (A[j] < A[minj])
	    minj = j;
    }
    swap=A[i];
    A[i] = A[minj];
    A[minj] = swap;
    if(i!=minj)
    count++;
  }
  
for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i!=n-1)
    printf(" ");
  }
  printf("\n");
  printf("%d\n",count);


  return 0;
}
