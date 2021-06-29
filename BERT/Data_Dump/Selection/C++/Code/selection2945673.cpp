#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n;
  int minj;
  int count = 0;
  int tmp;
  int i,j;
  int flug = 0;
  
  scanf("%d",&n);

  if(n < 1 || 100 < n)
    exit(0);

  int a[n];

  for(i = 0; i<n; i++){
    scanf("%d",&a[i]);
    if(a[i] < 0 || 100 < a[i]){
      exit(1);
    }
  }

  for(i=0; i<n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]){
	minj = j;
	flug = 1;
      }
    }
    if(flug == 1)
      count++;
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
    flug = 0;
  }

  for(i=0; i<n-1; i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[i],count);
}

