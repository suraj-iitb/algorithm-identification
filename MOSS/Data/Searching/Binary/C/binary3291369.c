#include<stdio.h>
#define MAX 100000
#define TRUE 1
#define FALSE 0

int binarySearch(int,int);
int S[MAX];
int main(){
  int i, n, q, T[MAX], C = 0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }
  for(i=0; i<q; i++){
  if(binarySearch(T[i],n) == TRUE) C++;
  }

  printf("%d\n",C);
  return 0;
}

int binarySearch(int key,int n){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key) return TRUE;
    else if(key < S[mid]) right = mid;
    else left = mid + 1;
  }
  return FALSE;
}

