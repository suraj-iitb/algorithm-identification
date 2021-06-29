#include<stdio.h>
#define N 100
int selectionSort(int*,int);

int main()
{
  int i,n,a[N],count;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  
  count = selectionSort(a,n);
  
  for(i=0; i<n; i++) {
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}

int selectionSort(int a[],int n)
{
  int i,j,minj,tmp,count=0;

  for(i=0; i<n-1; i++) {
    minj = i;
    for(j=i; j<n; j++)
      if(a[j]<a[minj]) minj = j;
    if(minj!=i){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count++;
    }
  }
  return count;
}
  
