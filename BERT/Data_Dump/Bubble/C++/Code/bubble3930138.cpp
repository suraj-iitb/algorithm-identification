#include<cstdio>
#include<algorithm>

int bubble_sort(int A[], int n) {
  bool flag = 1;
  int cnt = 0;
  int i = 0;
  while (flag) {
    flag = 0;
    for (int j = n - 1; 0 < j; j--) {
      if (A[j] < A[j - 1]) {
        std::swap(A[j - 1], A[j]);
        cnt++;
        flag = 1;
      }
    }
    i++;
  }
  return cnt;
}

int main() {
  int n;
  scanf("%d", &n);

  int A[n];
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);

  int cnt = bubble_sort(A, n);

  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  printf("%d\n", cnt);

  return 0;
}

