#include<stdio.h>

#define MAX_N 100000

int binary_search(int n, int key, int *S)
{
  int left = 0;   // first index of search range
  int right = n;  // next index of search range
  int mid;        // middle index of search range

  while (left < right) {
    mid = (left + right)/2;
    if (S[mid] == key)
      return mid;
    else if (key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return -1;
}
int main(void)
{
  int n, q, key;
  int S[MAX_N];

  // 入力処理
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d ", &S[i]);
  }
  scanf("%d", &q);
  int cnt = 0;
  for (int i = 0; i < q; i++) {
     scanf("%d ", &key);
     if (binary_search(n, key, S) != -1)
       cnt++;
  }

  printf("%d\n", cnt);
  return 0;

}
  

