#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N], K = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        K = max(K, a[i]);
    }

    int cnt[K + 1];
    fill(cnt, cnt + K + 1, 0);
    for (int i = 0; i < N; ++i) {
        ++cnt[a[i]];
    }

    for (int k = 0; k < K; ++k) {
        cnt[k + 1] += cnt[k];
    }

    int b[N];
    for (int i = 0; i < N; ++i) {
        b[cnt[a[i]] - 1] = a[i];
        --cnt[a[i]];
    }

    for (int i = 0; i < N; ++i) {
        cout << b[i] << (i < N - 1 ? " " : "");
    }
    cout << endl;
    return 0;
}

