#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

//配列出力処理
void output(int a[], int n) {
  rep(i, n) {
    if (i > 0) printf(" ");  //要素間に空白を入れる
    printf("%d", a[i]);  //フォーマット指定子 %c char %d int10進数
  }
  printf("\n");
}

// Insertion Sort
void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int duf = a[i];
    int j = i - 1;
    while (j >= 0 && duf < a[j]) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = duf;
    output(a, n);
  }
}

// O(n^2)
int main() {
  int n;
  int a[1000];
  cin >> n;
  rep(i, n) cin >> a[i];
  output(a, n);
  insertionSort(a, n);
  return 0;
}

