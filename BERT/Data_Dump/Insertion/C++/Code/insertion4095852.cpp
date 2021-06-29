#include <bits/stdc++.h>
using namespace std;

// 出力用関数
void trace(int A[], int N) {
  int i;

  for (i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void insertionSort(int A[], int N) {
  int j; // ソート済みからvを挿入する位置を探すループ変数
  int i; // 未ソートの先頭を示すループ変数
  int v; // A[i]の値を一時保存する変数

  for(i = 1; i < N; i++) { // 0は最初からソート済みとする
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v) { // jが0以上またはA[j]がvより大きいかぎり
      A[j + 1] = A[j]; // A[j + 1]に移動させる
      j--;
    }
    A[j + 1] = v;
    trace(A, N);
  }
}

int main() {
  int N, i;
  cin >> N;
  int A[N];

  for (i = 0; i < N; i++) {
    cin >> A[i]; // cinはスペースか改行で区切ってくれる
  }

  trace(A, N);
  insertionSort(A, N);

  return 0;
}

