#include <stdio.h>
#define N 100

int bubbleSort(int *a,int n);

main()
{
  int a[N],n,i,count;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  count = bubbleSort(a,n);
  printf("%d",a[0]);

  for(i=1; i<n; i++){
    printf(" %d",a[i]);
  }

  printf("\n%d\n",count);

  return 0;
}

int bubbleSort(int *a,int n)
{
  int i,j,temp,count=0;
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(a[j]<a[j-1]){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	count++;
      }
    }
  }
  return count;
}
