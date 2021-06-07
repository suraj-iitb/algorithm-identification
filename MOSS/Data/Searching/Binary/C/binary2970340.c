#include<stdio.h>

#define N 1000000

int A[N], n;

int binarySearch(int key){
  int left = 0;
  int mid;
  int right = n;
 
  while(left < right){
    mid = (left+right)/2;
    if(key == A[mid])    return 1;
    if(key>A[mid])       left = mid+1;
    else if              (key<A[mid])right=mid;
  }
  return 0;
}

int main(){
  int i, sum=0, s, t;
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  scanf("%d", &s);
for(i=0; i<s; i++){
 scanf("%d", &t);
 if( binarySearch(t))sum++;
  }


 printf("%d\n", sum);
  return 0;
}

