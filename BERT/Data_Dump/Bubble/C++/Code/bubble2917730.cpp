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

int bubbleSort(int n, int a[])
{
  // 未整列要素が残っている
  bool flag = true;

  // 未整列部分の先頭のインデックス
  // 初期値は 0
  int i = 0;

  int count = 0;

  int tmp;
  while (flag)
  {
    // もし内側のループが完了しているなら、フラグは false のままで、ソートは終了する
    flag = false;
    // 配列の末尾から未整列要素の2番目までループ
    for (int j = n - 1; j >= i + 1; j--)
    {
      // 順番が逆になっている未整列要素があれば、交換
      if (a[j] < a[j - 1])
      {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
        // 内側で交換したら、外側のループを実行できるようフラグを true にする
        // 内側で交換しなかったら、ソートは完了しているので、この時点でソートを終了する
        flag = true;
        count++;
      }
    }
  }

  display(n, a);
  cout << count << endl;

  return 0;
}

int main()
{
  int n;
  cin >> n;

  int a[100];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  bubbleSort(n, a);

  return 0;
}

