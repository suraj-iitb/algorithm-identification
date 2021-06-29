#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cnt(int b, int e) {
    if (e - b <= 1) return 0;
    int mid = (b + e) / 2;
    return cnt(b, mid) + cnt(mid, e) + e - b;
}

int main() {
    int N;
    cin >> N;

    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    sort(S.begin(), S.end());
    for (int i = 0; i < N; ++i) {
        cout << S[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
    cout << cnt(0, N) << endl;
    return 0;
}

