#include <stdio.h>

int main()
{

  int N, flag, j, b, count;

  scanf("%d",&N);

  int a[N];

  for(j=0;j<N;j++){
    scanf("%d",&a[j]);
  }

  count = 0;
  flag = 1;
  
  while(flag){
    flag = 0;
    for(j=0;j<N;j++){
      if(a[j]<a[j-1]){
	b = a[j];
	a[j] = a[j-1];
	a[j-1] = b;
	flag = 1;
	count++;
      }
    }
  }

  for(j=0;j<N;j++){
    if(j==N-1) printf("%d\n",a[j]);
    else printf("%d ",a[j]);
  }

  printf("%d\n",count);
    
  return 0;

}

