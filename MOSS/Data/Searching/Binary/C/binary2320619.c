#include <stdio.h>

int binarySearch(int);

int S[1000000], n;

int main()
{
  int q, T, C=0;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if( binarySearch(T) ) C++;
  }

  printf("%d\n",C);
  return 0;
}

int binarySearch(int T)
{
  int left=0, right=n, mid;

  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == T) return 1;
    if(T>S[mid]) left = mid + 1;
    else if(T < S[mid]) right = mid;
  }
  return 0;
}
