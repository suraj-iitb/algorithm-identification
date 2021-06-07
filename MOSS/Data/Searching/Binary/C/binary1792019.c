#include <stdio.h>
#define N 100000
#define Q 50000
#define notFound 0

int binarySearch(int[],int,int);

int main()
{
  int i,n,q,key,cnt=0;
  int S[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(S,key,n)){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  
  
  return 0;
}

int binarySearch(int A[],int key,int n)
{
  int left=0,right,mid;
  
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(A[mid] == key){
      return mid;
    }
    else if(key<A[mid]){
      right = mid;
    }
    else {
      left = mid+1;
    }
  }
  return notFound;
  
}
