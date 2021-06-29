#include <stdio.h>
#define MAX_A 10000
#define MAX_B 500

int main(){

  int n_1,n_2,i,j,sum=0,key,flag;
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
    for( i=0 ; i<n_1 ; i++ ){
      if( a[i] == key ) flag = 1;
      else continue;
    }
    if( flag == 1 ){
      sum++;
      flag = 0;
    }
    else continue;
  }
  printf("%d\n",sum);
  return 0;
}
