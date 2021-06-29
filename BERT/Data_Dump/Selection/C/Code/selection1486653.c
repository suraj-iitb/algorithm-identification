#include <stdio.h>

main()
{
  int a[100];
  int n, i, j, k, minj, count=0;

  scanf("%d", &n);

  for(i=0; i<n; i++){
	scanf("%d", &a[i]);
  }
  
  for(i=0; i<n-1; i++){
	minj = i;
	for(j=i; j<=n-1; j++){
	  if(a[j]<a[minj]){
		minj = j;
	  }
	}
	if(minj != i){
	  k = a[i];
	  a[i] = a[minj];
	  a[minj] = k;
	  count++;
	}
  }
  
  for(i=0; i<n; i++){
	printf("%d", a[i]);
	if(i== n-1) printf("\n");
	else printf(" ");
  }
  printf("%d\n", count);

  return 0;
}
