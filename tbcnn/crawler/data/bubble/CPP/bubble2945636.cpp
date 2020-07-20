#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n;
  int flag = 1;
  int i;
  int tmp;
  int count = 0;
  
  scanf("%d",&n);

  if(n < 1 || 100 < n)
    exit(0);
  
  int a[n];

  for(i = 0; i<n; i++){
    scanf("%d",&a[i]);
    if(a[i] < 0 || 100 < a[i])
      exit(1);
  }

  while(flag){
    flag = 0;
    for(i = n-1; i>0; i--){
      if(a[i] < a[i-1]){
	tmp = a[i];
	a[i] = a[i-1];
	a[i-1] = tmp;
	flag = 1;
	count++;
      }
    }
  }
  
  for(i=0; i<n-1; i++){
    printf("%d ",a[i]);
  }
  
  printf("%d\n%d\n",a[i],count);
  return 0;
}

  

