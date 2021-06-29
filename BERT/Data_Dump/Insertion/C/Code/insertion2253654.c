#include<stdio.h>
#include<stdlib.h>

int main(){
  int i, j, k, n, tmp;
  int A[100];

  scanf("%d",&n);
  if( n<1 || 100<n ) exit(1);
  
  for( i=0 ; i<n ; i++ ){
    scanf("%d",&A[i]);
    if( A[i]<0 || 1000<A[i] ) exit(2);
  }

  for( i=1 ; i<n ; i++ ){
    tmp = A[i];
    j = i-1;
    
    for( k=0 ; k<n ; k++ ){
      if( k==n-1 ) printf("%d\n",A[k]);
      else printf("%d ",A[k]);
    }
 
    while( j>=0 && A[j]>tmp ){
      A[j+1] = A[j];
      j--;
      A[j+1] = tmp;
    }
  }

  for( k=0 ; k<n ; k++ ){
    if( k==n-1 ) printf("%d\n",A[k]);
    else printf("%d ",A[k]);
    
  }
  return 0;
}
