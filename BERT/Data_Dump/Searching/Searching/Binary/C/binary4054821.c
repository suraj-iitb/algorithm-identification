#include<stdio.h>

#define N 100000

int binarySearch(int,int*,int);

int main(void){
  int S[N];
  int n,q,T,C=0;
  int i;

  scanf(" %d",&n);
  for(i = 0; i < n; i++){
    scanf(" %d",&S[i]);
  }
  scanf(" %d",&q);
  for(i = 0; i < q; i++){
    scanf(" %d",&T);
    C += binarySearch(n,S,T);
  }

  printf("%d\n",C);
  
  return 0;
}

int binarySearch(int n, int *S, int key){
  int left=0,right=n,mid;
  while(left < right){
    mid = (left + right) /2;
    if(S[mid] == key) return 1;
    else if(S[mid] > key) right = mid;
    else if(S[mid] < key) left = mid +1;
  }
  return 0;
}

