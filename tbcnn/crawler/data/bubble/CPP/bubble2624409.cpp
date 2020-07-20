#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 120000000

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flg = true;
    int cnt = 0;
    while (flg) {
        flg = false;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                cnt++;
                flg = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
