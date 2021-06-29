#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,j,n,m=0,minj,x;
  int *a;

  scanf("%d",&n);
  a = (int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j] < a[minj]) minj = j;
    }
    x = a[i];
    a[i] = a[minj];
    a[minj] = x;
    if(a[minj] != a[i]) m++;
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
