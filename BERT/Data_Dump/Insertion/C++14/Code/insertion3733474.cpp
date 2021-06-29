#include <bits/stdc++.h>

#define rp(i, n) for (int i = 0; i < n; i++)
#define rpn(i, n) for (int i = 0; i <= n; i++)
#define p(s) cout << s << endl
#define pc(condition, _true, _false) if (condition) _true; else _false;

using namespace std;
//
// Created by karayuu on 2019-3-28.
//
/**
 * 配列の要素を表示します.(1 2 3 4 5)のような感じ.
 *
 * @param a 表示したい配列
 * @param n 配列の要素数
 */
void printArray(const int a[], int n) {
  rp(i, n) {
    if (i != 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rp(i, n) {
    cin >> a[i];
  }

  rp(i, n) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    printArray(a, n);
  }
}


