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

    print(num);
    rep(i, 1, n) {
        int v = num[i];
        int j = i - 1;

        while (j >= 0 && num[j] > v) {
            num[j + 1] = num[j];
            --j;
        }
        num[j + 1] = v;
        print(num);
    }

    return 0;
}
