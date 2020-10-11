#include <stdio.h>

int main(){
  int i,j,n,min,r;
  int a[100];
  int flag=1, count=0;

  scanf("%d",&n);

  for(i=0; i<n; i++)
    scanf("%d",&a[i]);

  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++)
      if(a[j]<a[min])
	min = j;
    r=a[i];
    a[i]=a[min];
    a[min]=r;
    if(min!=i)
      count++;
    
  }
  for(i=0; i<n-1; i++)
    printf("%d ",a[i]);
  
  printf("%d\n%d\n",a[i],count);
  
  return 0;
}

