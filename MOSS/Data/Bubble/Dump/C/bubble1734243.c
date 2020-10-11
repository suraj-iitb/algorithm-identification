#include <stdio.h>
#define N 100

int main()
{
  int a[N], flag, i, j=0, n = 0, x, c = 0;
  
  scanf("%d",&x);

  for(i=0; i<x; i++) scanf("%d",&a[i]);

  i = 0;
  flag = 1;

  while(flag==1) {
    flag = 0;

    for(j=x-1; j>=i+1; j--){
      if(a[j]<a[j-1]){
	n = a[j];
	a[j] = a[j-1];
	a[j-1] = n;
	flag = 1;
	c++;
      }
    }
      i++;
    
  }

  for(j=0; j<x; j++){
    printf("%d",a[j]);
    if(j!=x-1) printf(" ");
  }
  printf("\n%d\n", c);


  return 0;
}
