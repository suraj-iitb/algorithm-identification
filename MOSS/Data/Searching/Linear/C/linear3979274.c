#include<stdio.h>
#define MAX_N 10000

int linear_search(int n, int key, int *S)
{
  S[n] =  key;
  int i = 0;
  while (S[i] != key)
    i++;
  if (i < n)
    return i;
  return -1;
}
int main(void)
{
  int n, q;
  int S[MAX_N+1];

  // 入力処理
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d ", &S[i]);
  }
  scanf("%d", &q);
  
  int cnt = 0, key;
  for (int i = 0; i < q; i++) {
    scanf("%d ", &key);
    if (linear_search(n, key, S) != -1)
      cnt++;
  }

  printf("%d\n", cnt);
  return 0;

}
  

