#include <iostream>
using namespace std;

int display(int n, int a[])
{
  for (int i = 0; i < n - 1; i++)
  {
    cout << a[i] << " ";
  }
  cout << a[n - 1] << endl;

  return 0;
}

int insertionSort (int n, int a[]) {
  int v, j;
  for (int i = 1; i < n; i++) {
    // 未整列部分の最初の値を v に保存
    v = a[i];
    // j は整列部分の最後の値のインデックス
    j = i - 1;
    // 整列部分を、v 以下の値が見つかるまで、右から左に見ていく
    // もし v 以下の値でなければ、その値をひとつ右にずらす
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    // 整列部分に v より小さい値が見つかれば、その値の次に v の値を挿入する
    // 左端まで見ても v より小さい値がなければ、先頭に v の値を挿入する
    a[j + 1] = v;
    display(n, a);
  }
}

int main()
{
  int n;
  cin >> n;

  int a[1000];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  display(n, a);

  insertionSort(n, a);

  return 0;
}

