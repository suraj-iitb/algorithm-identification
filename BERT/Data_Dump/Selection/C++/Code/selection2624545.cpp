// selection sort

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

    int minj;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            cnt++;
            swap(a[i], a[minj]);
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
