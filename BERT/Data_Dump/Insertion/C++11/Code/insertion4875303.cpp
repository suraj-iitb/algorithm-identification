#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
using T = tuple<int, int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define INF (ll)1e9
#define NINF (ll)-1e9
const int mod = 1e9 + 7;
const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};

void insertionSort(vector<int> &a, int n) {
    mrep(i, 1, n){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        rep(i, n){
            if(i != n - 1) cout << a[i] << " ";
            else cout << a[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        if(i != n - 1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    insertionSort(a, n);
    return 0;
}
