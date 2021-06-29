#include<stdio.h>
#define N 100000

int BinarySearch(int, int, int[]);

int main(){
  int len=0,key=0,s[N],t,i,count=0;

  scanf("%d",&len);
  for( i = 0 ; i < len ; i++ ){
    scanf("%d",&s[i]);
  }

  scanf("%d",&key);
  for( i = 0 ; i < key ; i++ ){
    scanf("%d",&t);
    count += BinarySearch(len,t,s);
  }
  printf("%d\n",count);

  return 0;
}

int BinarySearch(int r,int k,int data[]){
  int l=0,mid=0;

  while( l < r ){
    mid = (l + r) / 2;

    if( k == data[mid] ) return 1;

    if( k < data[mid] ) r = mid;
    else if( k > data[mid] ) l = mid+1;
  }

  return 0;
}

