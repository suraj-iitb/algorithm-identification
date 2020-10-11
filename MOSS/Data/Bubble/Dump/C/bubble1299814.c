#include <stdio.h>

main()
{

  int i, j, n, k, flag, count=0;
  int A[100];

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
	scanf("%d", &A[i]);
  }

  flag=1;
  while(flag){
	flag=0;
	for(j=n-1; j>=1; j--){
	  if(A[j]<A[j-1]){
		k = A[j];
		A[j] = A[j-1];
		A[j-1] = k;
		flag=1;
		count++;
	  }
	}
  }
  
  
  for(i=0; i<n; i++){
	printf("%d", A[i]);
	if(i== n-1) printf("\n");
	else printf(" ");
  }
  printf("%d\n", count);

return 0;
}
