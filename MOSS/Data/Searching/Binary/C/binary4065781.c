#include <stdio.h>
#define N 100000
#define F 50000
#define FOUND 1
#define NOT_FOUND 0

int binarySearch(int *,int,int);

int main(){
  int array[N];
  int i,a,b,c,key,cnt=0;
  
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&array[i]);
  }

  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&key);
    c=binarySearch(array,key,a);
    if(c==1) cnt++;
  }

  printf("%d\n",cnt);
  
  return 0;
}

int binarySearch(int *A,int key,int n){
  int left=0;
  int right=n;
  int mid=0;
  while(left<right){
    mid=(left + right)/2;
    if(A[mid] == key){
      return FOUND;
    } else if(key<A[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return NOT_FOUND;
}


