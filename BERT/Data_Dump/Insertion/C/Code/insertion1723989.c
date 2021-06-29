#include<stdio.h>

int main()
{

  int n,a[1000],i,j,key,u;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i < n-1;i++){
    printf("%d ",a[i]);
  }

  printf("%d\n",a[i]);

  for( i = 1 ; i < n ; i++){
    key = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > key)
      {
	a[j+1] = a[j];
	j--;
	a[j+1]= key;
      }

    for(u=0;u<n-1;u++){
      printf("%d ",a[u]);
    }

    printf("%d\n",a[u]);

  }

  return 0;
}
