#include<stdio.h>
#define MAX 100

int binarySearch( int );

int n,A[100000];

int main(){
  int i,j,q,k,sum=0;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for( j = 0 ; j < q ; j++ ){
    scanf("%d",&k);

    if( binarySearch(k) == 1 ) sum++;

  }
  
  printf("%d\n",sum);

  return 0;
}

int binarySearch( int x ){
  int left = 0;
  int right = n;

  while( left < right ){
    int mid = ( left + right ) / 2;

    if( A[mid] == x ) return 1;

    else if( x < A[mid] ) right = mid;

    else left = mid + 1;
  }
  return 0;
}
