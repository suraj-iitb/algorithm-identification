#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    
    int n; cin >> n;
    vi a(n); REP(i, n) cin >> a[i];
    cout << a[0];
    FOR(j, 1, n) cout << " " << a[j];
    cout << endl;
    FOR(i, 1, n) {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        cout << a[0];
        FOR(j, 1, n) cout << " " << a[j];
        cout << endl;
    }
    

    return 0;
}
