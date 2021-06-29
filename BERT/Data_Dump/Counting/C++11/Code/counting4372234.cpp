#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void counting_sort(vector<int> a, vector<int> &b, int k) {
    vector<int> c(k);
    int n = a.size();

    rep(i, n) {
        c.at(a.at(i))++;
    }
    for (int i = 1; i < k; i++) {
        c[i] = c[i] + c[i-1];
    }

    for (int i = n-1; 0 <= i; i--) {
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a.at(i);
    counting_sort(a, b, 10000);

    rep(i, n) {
        cout << b.at(i);
        if (i != n -1) cout << " ";
    }
    cout << endl;
}
