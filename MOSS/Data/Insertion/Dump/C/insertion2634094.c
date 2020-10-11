#include <stdio.h>

int GetMinIndex(int *a, int start, int len) {
  int min = a[start], minIndex = start;
  for (int i = start + 1; i < len; i++) {
    if (min > a[i]) {
      min = a[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void Swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void ReadArray(int *a, int len) {
  for (int i = 0; i < len; i++) {
    scanf("%d", &a[i]);
  }
}

void PrintArray(int *a, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d%c", a[i], i + 1 == len ? '\n' : ' ');
  }
}

void InsertionSort(int *a, int len) {
  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A
  PrintArray(a, len);
  for (int i = 1; i < len; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
      a[j + 1] = v;
    }
    PrintArray(a, len);
  }
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  int a[N];
  ReadArray(a, N);
  InsertionSort(a, N);

  return 0;
}
