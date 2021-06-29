#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND 10000000
int binarySearch(int);
int n, q, *S, *T;
int main()
{
  int i, count = 0;

  scanf("%d",&n);
  S = (int *)malloc(n * sizeof(int));
  
  for(i = 0 ; i < n ; i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  T = (int *)malloc(q * sizeof(int));

  for(i = 0 ; i < q ; i++) scanf("%d",&T[i]);

  for(i = 0 ; i < q ; i++){
    if(binarySearch(T[i]) != NOT_FOUND) count++; } 

  printf("%d\n",count);

  return 0;
}

int binarySearch(int key)
{
  int left, right, mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key) return mid;
    else if(key < S[mid]) right = mid;
    else left = mid + 1; }

  return NOT_FOUND;
}

