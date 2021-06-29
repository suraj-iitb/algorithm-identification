#include<cstdio>
#include<limits>

#define MAX 500000
#define INFINITE numeric_limits<int>::max()

using namespace std;

int S[MAX];
int cnt = 0;

void print(int A[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void merge(int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) L[i] = S[left + i];
  for (int i = 0; i < n2; i++) R[i] = S[mid + i];
  L[n1] = R[n2] = INFINITE;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      S[k] = L[i];
      i++;
    } else {
      S[k] = R[j];
      j++;
    }
  }
}

void merge_sort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid, right);
    merge(left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &S[i]);
  merge_sort(0, n);

  print(S, n);
  printf("%d\n", cnt);

  return 0;
}

