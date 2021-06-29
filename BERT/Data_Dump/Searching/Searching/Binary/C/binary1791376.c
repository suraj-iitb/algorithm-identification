#include <stdio.h>

int S[1000000], n;

int BinarySearch(int key)
{
  int left=0, right=n, mid;

  while(left < right){
    mid = (left+right)/2;
    if(S[mid] == key) return 1;
    else if(key < S[mid]) right = mid;
    else left = mid+1;
  }
  return 0;
}

int main()
{
  int i, q, T[50000], C=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
    if(BinarySearch(T[i]) == 1) C++;
    else ;
  }

  printf("%d\n", C);
  return 0;
}
