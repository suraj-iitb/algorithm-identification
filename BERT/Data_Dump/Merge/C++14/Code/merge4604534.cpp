//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto merge = [&](vi &a, int left, int mid, int right) {
        int cnt = 0;
        int n1 = mid - left;
        int n2 = right - mid;
        vi l(n1+1), r(n2+1);
        rep(i, n1) {
            l[i] = a[left+i];
        }
        rep(i, n2) {
            r[i] = a[mid+i];
        }
        l[n1] = INT_MAX;
        r[n2] = INT_MAX;
        int i = 0;
        int j = 0;
        for(int k = left; k < right; k++) {
            if(l[i] <= r[j]) {
                a[k] = l[i++];
            }
            else {
                a[k] = r[j++];
            }
            cnt++;
        }
        return cnt;
    };

    function<int(vi&, int, int)> mergeSort = [&](vi &a, int left, int right) {
        int res = 0;
        if(left+1 < right) {
            int mid = (left + right)/2;
            res += mergeSort(a, left, mid);
            res += mergeSort(a, mid, right);
            res += merge(a, left, mid, right);
        }
        return res;
    };

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int ans = mergeSort(a, 0, n);
    rep(i, n) cout << a[i] << (i == n-1?'\n':' ');
    cout << ans << endl;

}
