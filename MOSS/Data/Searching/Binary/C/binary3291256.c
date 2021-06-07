#include <stdio.h>
#define N 100000
#define M 50000
int binarySearch(int,int[],int);
int main(){
  int a[N],b[M];
  int x,y,i,j,s=0;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<y;i++){
    if(binarySearch(b[i],a,x)==1){
      s++;
    }
  }
  printf("%d\n",s);
  return 0;
}

int binarySearch(int d,int a[],int x){
  int left = 0;
  int right,mid;
  right = x;
  while(left < right){
    mid = (left + right)/2;
    if(a[mid]==d){
      return 1;
    }else if(d<a[mid]){
      right=mid;
    }else{
      left = mid +1;
    }
  }
  return 0;
}
