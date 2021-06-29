#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int c = 0;
    vector<int> v(N);
    for (auto& x: v) cin >> x;
    for (int i = 0; i < N; i++) {
        int mi = i;
        for (int j = i; j < N; j++) {
            if (v[j] < v[mi]) mi = j;
        }
        if (i != mi) {
            c++;
            swap(v[mi], v[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl << c << endl;
}

