#include<stdio.h>
#define N 100
main()
{
  int n, A[N], i, j, k,c=0, minj;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<n-1; i++){
    minj = i;
    for(j=i; j<=n-1; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] != A[minj]){
    k = A[i];
    A[i] = A[minj];
    A[minj] = k;
    c++;
    }
  }
  for(j=0; j<n; j++){
    printf("%d",A[j]);
    if(j == n-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n",c);
  return 0;
}
