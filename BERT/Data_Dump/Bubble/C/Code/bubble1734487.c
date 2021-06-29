#include <stdio.h>

#define N 100

int main(){

  int A[100];
  int i,j,flag=1,a,swap,n,count=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    }
  while(flag){
    flag=0;

    for(j=n-1; j>=1; j--){
      
      if (A[j] < A[j-1]){
	swap=A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	count++;
	flag=1;
      } 
    }
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
