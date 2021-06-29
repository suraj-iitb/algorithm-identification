#include<stdio.h>

int A[100000],n;

int Binary( int key ){
  int left = 0;
  int right = n;
  int mid;
  while( left < right ){
    mid = ( left + right )/2;
    if( key == A[mid] ){
      return 1;
    }
    else if(key > A[mid] ){
      left = mid + 1;
    }
    else {
      right =mid;
    }
  }
  return 0;
}

int main(void){

  int i,q,m,sum=0;
  scanf("%d",&n);
  for( i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for( i = 0 ; i < q ; i++){
    scanf("%d",&m);
    if( Binary(m)){
      sum++;
    }
  }
  printf("%d\n",sum);
 
 return 0;
}
