#include <stdio.h>
#define MAXS 10000
#define MAXT 500

int LinearSearch(int A[],int n, int key)
{
  int i=0;
  A[n] = key;
  while( A[i] != key ) i++;
  return i != n; 
}

int main()
{
  int n,q,S[MAXS],T[MAXT],result,count=0,i;

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for( i=0 ; i<q ; i++ ){
    scanf("%d",&T[i]);
  }

  for( i=0 ; i<q ; i++ ){
    result = LinearSearch(S,n,T[i]);
    if( result==1 ) count++;
  }

  printf("%d\n",count);

  return 0;
  
  
}

