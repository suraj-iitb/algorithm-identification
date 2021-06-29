#include<stdio.h>
#define N 10000
#define M 500
int main(){
  int n,q,key;
  int i,j,r;
  int gen = 0;
  int count = 0;
  int S[N],T[M];
  
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for( i=0 ; i<q ; i++ )
    scanf("%d",&T[i]);

  for( i=0 ; i<q ; i++ ){
    key = T[i];

    for( j=0 ; j<n ; j++ ){
  
     if( key == S[j] ){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);
  
  return 0;
}

