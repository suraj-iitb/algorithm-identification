#include<stdio.h>
#define N 500000

int a[N],n1,n2,number,count;

int searchNumber(int);

int searchNumber(int x){
  int left,right,mid;
  left = 0;
  right = n1;
  while( left < right ){
    mid = ( left + right ) / 2;
    if( a[mid] == x ) return a[mid];
    else if ( x < a[mid] ) right = mid;
    else left = mid + 1;
  }
  return -1;
}

int main(){

  int i,j;
  int b[N];
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&b[i]);
    number = searchNumber(b[i]);
    if( number != -1 ) count++;
  }

  printf("%d\n",count);
  return 0;
}
