#include <stdio.h>

#define NUM 100

int main()
{
  int i,j;
  int n,a[NUM],minj,k,count = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    if(i != minj) count++;
    k = a[i];
    a[i] = a[minj];
    a[minj] = k;
  }

  printf("%d",a[0]);
  for(i = 1;i < n;i++){
    printf(" %d",a[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

