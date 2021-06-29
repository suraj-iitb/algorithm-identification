#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int R[], int N) {// Nは配列の要素数
    int count = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = N-1; j > i; j--) {
            if (R[j-1] > R[j]) {
                swap(R[j], R[j-1]);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    int R[110];
    for (int i = 0; i < N; i++) cin >> R[i];

    int count = bubbleSort(R, N);

    for (int i = 0; i < N; i++) {
        if (i == N-1) cout << R[i] << endl;
        else cout << R[i] << " ";
    }
    cout << count << endl;

    return 0;
}
