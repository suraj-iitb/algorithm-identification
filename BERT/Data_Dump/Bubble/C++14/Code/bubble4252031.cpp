#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

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

    bool flag = true;
    int cnt = 0;

    while (flag) {
        flag = false;
        rrep(i, 1, n) {
            if (num[i - 1] > num[i]) {
                swap(num[i - 1], num[i]);
                flag = 1;
                ++cnt;
            }
        }
    }
    print(num);
    cout << cnt << endl;

    return 0;
}
