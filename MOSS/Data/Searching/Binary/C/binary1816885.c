#include<stdio.h>
#define MAX 100000
#define M 50000
#define NOT_FOUND -1

int binarySearch(int *,int,int);

int main()
{
  int i,n,q,x,count;
  int A[MAX],B[M];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&B[i]);
  }

  for(i = 0;i < q;i++){
    x = binarySearch(A,n,B[i]);
    if(x != NOT_FOUND) count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int *A,int n,int key)
{
  int left=0,right=n,mid;

  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key) return mid;
    else if(key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}
