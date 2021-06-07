#include<stdio.h>
#define N 100000
#define q 50000
int binarySearch(int *,int,int);


int main(){
  int a[N],x,y,i,j,count=0,r;

  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
   scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&r);
    j=binarySearch(a,x,r);
    if(j==1) count++;
  }

  printf("%d\n",count);
  
  return 0;
}


int binarySearch(int *a,int x,int key){
  int left = 0,right = x,mid;
  while(left<right){
    mid = (left + right)/2;
    if(a[mid]==key) return 1;
    else if(key<a[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
  
}
