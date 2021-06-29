#include <iostream>
using namespace std;
static const int MAX = 200000;

int main() {
    int N;
    cin >> N;
    int R[MAX];
    // 配列を読み込み
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }
    for (int i = 0; i < N; i++) {
        int v = R[i];
        int j = i - 1;
        while (j >= 0 && R[j] > v) {
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = v; // 実質最後のR[j]に代入しているのと同じ
        for (int k = 0; k < N; k++) {
            if (k == N-1) {
                cout << R[k] << endl;
            } else {
                cout << R[k] << " ";
            }
        }
    }
    return 0;
}
