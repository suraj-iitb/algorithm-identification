#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int selectionSort(vector<int> &a, int n){
    int ans = 0;
    rep(i,n){
        int m = i;
        for(int j = i; j < n; ++j){
            if(a[j] < a[m]) m = j;
        }
        if(a[i] == a[m]) continue;
        swap(a[i], a[m]);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = selectionSort(a, n);
    rep(i,n){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}
