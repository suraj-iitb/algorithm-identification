#include <stdio.h>

int binarySearch(int ,int* ,int);

int main()
{
  
  int count=0;
  int a;
  int i,t[100000];
  int b;
  int c;
  
  scanf("%d",&a);
  
  for(i = 0;i < a;i++){
    scanf("%d",&t[i]);
  }
  
  scanf("%d",&b);
  
  for(i = 0; i < b; i++){
    scanf("%d",&c);
    count += binarySearch(a,t,c);
  }
  
  printf("%d\n",count);
  
  return 0;
}



    
int binarySearch(int x, int *y, int z)
{
  int right,left,mid;
  left = 0;
  right = x;
  while( right > left+1 ) {
    mid = ( right + left )/2;
    if ( y[mid] >  z ) right = mid;
    else left = mid;
  }
  
  return y[left] == z;
}

