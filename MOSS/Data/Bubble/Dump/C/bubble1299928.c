#include<stdio.h>
#include<stdlib.h>
#define  N 100

main(){
  int A[N],n,a,i,j,count=0;

  scanf("%d",&n);
  if(n>N)
    exit(1);

  for( i= 0 ; i< n ; i++)
    scanf("%d",&A[i]);

  for (i = 0;i < n-1; i++){
    for (j = n - 1; j > i; j--){
      if (A[j - 1] > A[j]){
	a = A[j];
	A[j] = A[j - 1];
	A[j - 1] = a;
	count++;
      }
    }
  }
  for( i=0 ; i<n ;i++){
    printf("%d",A[i]);
    if ( i != n - 1)
      printf(" ");
  }
 
  printf("\n%d\n",count);
   
  return 0;
  
}
