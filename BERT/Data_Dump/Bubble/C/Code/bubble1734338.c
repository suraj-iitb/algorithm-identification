#include<stdio.h>

int main()
{

  int i,j,n,a[100],flag=0,sw,u,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){

  scanf("%d",&a[i]);

  }

  flag = 1;
  i=0;
  while(flag){
    flag = 0;

    for (j = n - 1; j >= i+1; j--) {
      if (a[j - 1] > a[j]) { 
	sw = a[j];        
	a[j] = a[j - 1];
	a[j - 1]= sw;
	flag = 1;
	count++;
      }

    }
    i++;
  }

  for(u=0;u<n-1;u++){
    printf("%d ",a[u]);
 }
  printf("%d",a[u]);
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}
