#include<stdio.h>
#define MAX 100

int bubbleSort(int *,int);

int main()
{
  int a[MAX];
  int i,n,count;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  count = bubbleSort(a,n);

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",count);

  return 0;
}

int bubbleSort(int *A,int N)
{
  int flag = 1;
  int i,x,count = 0;

  while(flag){
    flag = 0;
    
    for(i=N-1;i>0;i--){
      if(A[i] < A[i-1]){
	x = A[i];
	A[i] = A[i-1];
	A[i-1] = x;
	flag = 1;
	count++;
      }
    }
  }

  return count;
}
  
  

