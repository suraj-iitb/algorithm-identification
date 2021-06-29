#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int flag = 1;
  int n;
  int *a;
  int i,j;
  int temp;
  int count = 0;
  
  scanf("%d",&n);
  a = (int *)malloc(sizeof(int) *n);
  
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  while(flag){
    flag = 0;
    for(j=(n-1); j>=1; j--){
      if(a[j] < a[j-1]){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	flag = 1;
	count ++;
      }
    }
  }

  for(i=0; i<n; i++){
    printf("%d",a[i]);
    if(i != (n-1)){
      printf(" ");
    }
  }
  printf("\n%d\n",count);

  free(a);
  
  return(0);
}
