#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int> as(n);
    rep(i, n) cin>>as[i];

    int k = 10010;
    vector<int> bs(n), cs(k);

    rep(i, n) cs[as[i]]++;
    rep(i, k - 1) cs[i + 1] += cs[i];
    rep(i, n) {
        cs[as[i]]--;
        bs[cs[as[i]]] = as[i];
    }

    rep(i, n - 1) cout<<bs[i]<<" ";
    cout<<bs[n - 1]<<endl;
}
