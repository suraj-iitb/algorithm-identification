#include <stdio.h>

#define N 100001
#define Q 50001

int binarySearch(int *, int, int);

int main(){
  int i, n, q, S[N], T[Q], cnt = 0;

  scanf("%d", &n);
  for(i = 1; i <= n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i = 1; i <= q; i++) scanf("%d", &T[i]);

  for(i = 1; i <= q; i++) if(binarySearch(S, n, T[i])) cnt++;

  printf("%d\n", cnt);

  return 0;
}

int binarySearch(int *S, int n, int key){
  int left = 1, right = n + 1, mid;

  while(left < right){
    mid = (double)(left + right)/2;

    if(S[mid] == key) return mid;
    else if(S[mid] > key) right = mid;
    else left = mid + 1;
  }

  return 0;
}
