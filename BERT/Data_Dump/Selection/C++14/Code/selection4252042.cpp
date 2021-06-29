#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); i++)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void print(const vi& num) {
    int n = num.size();
    rep(i, 0, n) {
        cout << num[i];
        if (i != n - 1) { cout << " "; }
        else { cout << endl; }
    }
}

int main() {
    int n;
    cin >> n;

    vi num(n);
    rep(i, 0, n) { cin >> num[i]; }

    int cnt = 0;
    rep(i, 0, n) {
        int min_index = i;
        int min_val = num[i];

        rep (j, i + 1, n) {
            if (min_val > num[j]) {
                min_val = num[j];
                min_index = j;
            }
        }
        if (i != min_index) {
            swap(num[i], num[min_index]);
            ++cnt;
        }
    }

    print(num);
    cout << cnt << endl;
    return 0;
}
