#include <stdio.h>

#define N 100000

int Search(int S[], int n, int key)
{
  int left = 0;
  int right = n;
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(key == S[mid])  return 1;
    if(key > S[mid]) left = mid +1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}

int main()
{

  int i, S[N], n, q, count = 0, T;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d",&q);
  
  for(i = 0; i < q; i++) {
    scanf("%d",&T);
    if( Search(S, n, T) == 1 ) count++;
	 }
  
    printf("%d\n", count);

    return 0;
}
