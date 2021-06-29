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

    for (int i = 0; i < n; i++) {
        int v = a[i];
        int j;
        for (j = i - 1; a[j] > v; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = v;

        for (int j = 0; j < n; j++) {
            cout << a[j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
