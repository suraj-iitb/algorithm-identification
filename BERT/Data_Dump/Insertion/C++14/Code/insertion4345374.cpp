#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//挿入ソート
int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    rep(i,n)cin >> a.at(i);
    rep(k,n)cout << (k?" ":"") << a[k];
    cout << "\n";
    
    for(int i = 1;i<n;i++){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            swap(a[j+1],a[j]);
            --j;
        }
        a[j+1] = v;
        rep(k,n)cout << (k?" ":"") << a[k];
        cout << "\n";
    }
    return 0;
}
/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/
