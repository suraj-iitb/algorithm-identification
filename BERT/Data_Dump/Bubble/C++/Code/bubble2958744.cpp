#include<iostream>
using namespace std;

// flagを用いたバブルソート
int bubbleSort(int A[], int N) {
  int sw_cnt = 0;
  bool flag = 1; // 1:未完了 | 0:完了
  // iを増やしながら、flagの値によるwhileをforで再現
  for (int i = 0; flag; i++) {
    // 何もなければ完了とする
    flag = 0;
    //iが下から迫り、jが上から迫るので、徐々に探索範囲は狭まる
    for (int j = N - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        // 交換がある限りは未完了にする
        flag = 1;
        sw_cnt++;
      }
    }
  }
  return sw_cnt;
}

int main() {
  int N, sw_cnt;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  sw_cnt = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    //  最初(i=0)以外は自分の前にスペースを置く
    if (i) cout << " ";
    cout << A[i];
  }

  cout << endl;
  cout << sw_cnt << endl;

  return 0;
}

