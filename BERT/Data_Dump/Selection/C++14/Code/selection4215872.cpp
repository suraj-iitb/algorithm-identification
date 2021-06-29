#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i = (a-1); i >= (b); --i)
#define RREP(i,n) RFOR(i,n,0)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int selectionSort(vi &a)
{
    int cnt = 0;
    REP(i, a.size()) {
        int minj = i;
        FOR(j, i, a.size()) {
            if(a[minj] > a[j]) minj = j;
        }
        if(i != minj) {
            cnt++;
            swap(a[i], a[minj]);
        }
    }
    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    
    int n; cin >> n;
    vi a(n); REP(i, n) cin >> a[i];

    int cnt = selectionSort(a);
    cout << a[0];
    FOR(i, 1, n) cout << " " << a[i];
    cout << endl << cnt << endl;


    return 0;
}
