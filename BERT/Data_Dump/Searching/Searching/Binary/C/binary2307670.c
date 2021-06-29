#include<stdio.h>

#define nmax 100000
#define qmax 50000

int binarySearch(int);

int n;
int A[nmax];

int main(){
  int q, i, cnt=0;
  int B[qmax];
  
  scanf("%d",&n);
  for(i=0; i<n ; i++) scanf("%d",&A[i]);
  
  scanf("%d",&q);
  for(i=0; i<q ; i++) scanf("%d",&B[i]);

  for(i=0 ; i<q ; i++) cnt += binalySearch(B[i]);

  printf("%d\n",cnt);
  return 0;
}

int binalySearch(int key){
  int left, right, mid;

  left = 0;
  right = n;
  
  while(left<right){

    mid = (left + right) / 2;

    if(key == A[mid]) return 1;

    if(key > A[mid]) left = mid + 1;

    else if(key < A[mid]) right = mid;
  }

  return 0;
}
