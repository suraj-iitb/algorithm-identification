#include <stdio.h>
#define MAX 100000

int S[MAX];

int binSearch(int key, int n) {
  int lowest, highest, middle;
  lowest = 0;
  highest = n - 1;
  middle = (highest + lowest) / 2;

  while(lowest <= highest) {
    if(key == S[middle])
      return 1;
    else if(key > S[middle])
      lowest = middle + 1;
    else
      highest = middle - 1;

    middle = (highest + lowest) / 2;
  }

  return key == S[middle];
}

int main() {
  int i, n, q, tmp, cnt;
  cnt = 0;

  scanf("%d", &n);
  for(i = 0;i < n;i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i = 0;i < q;i++) {
    scanf("%d", &tmp);
    if(binSearch(tmp, n))
      cnt++;

  }

  printf("%d\n", cnt);

  return 0;
}

