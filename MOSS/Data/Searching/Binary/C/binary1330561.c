#include <stdio.h>
#define MAX_A 100000
#define MAX_B 50000

int main(){

  int n_1,n_2,i,j,sum=0,key,left,right,mid,flag;
  int a[MAX_A],b[MAX_B];


  scanf("%d",&n_1);
  for( i=0 ; i<n_1 ; i++ ){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n_2);
  for( i=0 ; i<n_2 ; i++ ){
    scanf("%d",&b[i]);
  }

  for( j=0 ; j<n_2 ; j++ ){
    key = b[j];
    left = 0;
    right = n_1;
    while( left < right ){
      mid = (left + right)/2;
      if( key == a[mid] ){
	flag = 1;
	break;
      }
      if( key > a[mid] ) left = mid+1;
      else if( key < a[mid] ) right = mid;
    }
    if( flag == 1 ){
      sum++;
      flag = 0;
    }
  }

  printf("%d\n",sum);
  return 0;

}
