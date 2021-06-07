#include <stdio.h>

int binarySearch(int *,int,int);

int main()
{
  int i,n,q,A[100000+1],key,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(A,key,n)) count++;
  }
    printf("%d\n",count);

    return 0;
}

int binarySearch(int A[],int key,int n)
{
  int left,right,mid;

    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(A[mid] == key) return 1;
      else if(key < A[mid]) right = mid;
      else left = mid + 1;
    }
      return 0;
}

