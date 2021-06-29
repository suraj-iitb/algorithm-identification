#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,j,n,m=0,flag,x;
  int *a;
  
  scanf("%d",&n);
  a = (int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  

  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j = n-1;j>=i+1;j--){
      if(a[j] < a[j-1]){
	x = a[j];
	a[j] = a[j-1];
	a[j-1] = x;
	flag = 1;
	m++;
      }
    }
    i++;
  }
  for(i=0;i<n;i++){
    if(i > 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",m);
  free(a);
  return 0;
}
