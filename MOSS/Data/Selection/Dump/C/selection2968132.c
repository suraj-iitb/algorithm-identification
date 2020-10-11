// selection sort
#include <stdio.h>
int main() {
  int i, j, min, tmp, N, count = 0;
  int num[100];

  // input the number of element for array
  scanf("%d", &N);

  for (i = 0; i < N; i++)
    scanf("%d", &num[i]);

  for (i = 0; i < N - 1; i++) {
    min = i;
    for (j = i; j < N; j++) {
      if (num[min] > num[j])
        min = j;
    }
    tmp = num[min];
    num[min] = num[i];
    num[i] = tmp;
    if (i != min)
      count++;
  }

  for (i = 0; i < N; i++) {
    if (i == N - 1)
      printf("%d\n", num[i]);
    else
      printf("%d ", num[i]);
  }

  printf("%d\n", count);

  return 0;
}

//選択ソート
//選択ソートは配列の最小値(最大値)をもつ要素を探して、それを配列の先頭と交換することで整列を行うアルゴリズムである
//アルゴリズム分析。
// 1. 配列の先頭要素を仮の最小値をもつ要素(A0)としておく。
// 2.
// (A0)と(A0)以外の要素の値を比較して(A0)より小さい値を持つ要素(A1)が見つかれば(A1)と(A0)の値を交換する。
// 3. 2.を繰り返すことで(A0)には配列内での最小値がセットされる。
// 4.
// 次は(A0)をのぞいて(A1)と(A1)以外の要素、(A1)をのぞいて(A2)と(A2)以外の要素を比較/交換して整列が完了する。
