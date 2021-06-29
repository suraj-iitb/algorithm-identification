#include <stdio.h>
#define MAXS 100000
#define MAXT 50000

int binarySearch(int A[],int n,int key )
{
  int left=0,right=n,mid;
  while(left<right){
    mid = (left+right)/2;
    if( key == A[mid] )
      return 1;
    else if( key > A[mid] )
      left = mid+1;
    else
      right = mid;
  }
    return 0;
  
}

int main()
{
  int n,q,S[MAXS],T[MAXT],i,count=0;

  scanf("%d",&n);
  for( i=0 ; i<n; i++ ){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for( i=0 ; i<q ; i++ ){
    scanf("%d",&T[i]);
    if( binarySearch(S,n,T[i]) )
      count++ ;
  }


  printf("%d\n",count);

  return 0;
  
}

