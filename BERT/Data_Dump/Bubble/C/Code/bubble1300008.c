#include<stdio.h>
#define N 100
main()
{
  int n, A[N], i, j, k,flag=1, c=0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag = 0;
    for(j=n-1; j>=1; j--){
      if(A[j] < A[j-1]){
	k = A[j];
	A[j] = A[j-1];
	A[j-1] = k;
	c++;
	flag = 1;
      }
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
