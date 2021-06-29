#include<stdio.h>
#define N 100000

int binarySearch(int,int);

int A[N];

int main()
{
  int n,m,i,count=0,key;
  
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&m);
  for(i = 0 ; i < m ; i++){
    scanf("%d",&key);

    if(binarySearch(key,n) != -1) count++; 
  }

  printf("%d\n",count);

  return 0;
}

    int binarySearch(int key, int n)
  {
    int left = 0, right = n, mid;

    while(left < right){
      mid = (left + right)/2;
      
      if(A[mid] == key) return mid;

      else if(key < A[mid]) right = mid;

      else left = mid + 1;

    }
    return -1;
  }
