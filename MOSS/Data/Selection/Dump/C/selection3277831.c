#include<stdio.h>
#define MAX 100

int selectionSort(int *,int);

int main()
{
  int n,i,a[MAX],count;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  count = selectionSort(a,n);

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",count);

  return 0;
}

int selectionSort(int *A,int N)
{
  int i,j,x,min,count=0;

  for(i=0;i<N-1;i++){
    min = i;
    
    for(j=i;j<N;j++){
      if(A[j] < A[min]) min = j;
    }
    
    x = A[i];
    A[i] = A[min];
    A[min] = x;
    if(min != i) count++;
  }
  return count;
}

  
  

  

