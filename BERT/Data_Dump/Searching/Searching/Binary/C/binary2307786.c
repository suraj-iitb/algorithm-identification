#include<stdio.h>
#include<stdlib.h>

int search(int);

int n, q, i, c=0;
int S[100000];
int T[50000];

int main(){
 
  scanf("%d",&n);
  if( n>100000 ) exit(1);

  for( i=0 ; i<n ; i++ ){
    scanf("%d",&S[i]);
    if( S[i]<0 || 1000000000<S[i] ) exit(2);
  }
  
  scanf("%d",&q);
  if( q>50000 ) exit(3);

  for( i=0 ; i<q ; i++ ){
    scanf("%d",&T[i]);
    if( T[i]<0 || 1000000000<T[i] ) exit(4);
  }

  for( i=0 ; i<q ; i++ ){    
    if(search(T[i]) == 1){
      c++;
    }
  }

  printf("%d\n",c);
  return 0;
}

int search(int x){
  int right = n, left = 0;
  int middle = (right+left)/2;


  while( left<right ){
    middle = (left+right)/2;

    if( x == S[middle] ) return 1;
    if( x > S[middle] ) left = middle+1;
    else if( x < S[middle] ) right = middle;
  }
  

  return 0;
}
