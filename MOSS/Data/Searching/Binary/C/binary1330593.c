#include<stdio.h>
#define N 100000
#define Q 50000

int S[N],a;
int binarySearch( int );


int binarySearch( int key ){
  
  int left = 0,right,mid;
  
  right = a ;

  while( left < right ){
    mid = ( left + right )/2;
    if( S[mid] == key )
      return 1;
    else if( S[mid] < key )
      left = mid + 1;
    else if( S[mid] > key )
      right = mid;
	}
  return 0;
}

main(){
  int T[Q],b,count=0,i;
  
  scanf("%d",&a);
  for( i =0 ; i < a ; i++ )
    scanf("%d",&S[i]);
  scanf("%d",&b);
  for( i = 0 ; i < b ; i++ ){
    scanf("%d",&T[i]);
    count += binarySearch(T[i]);
      }

  printf("%d\n",count);

  return 0;
}
