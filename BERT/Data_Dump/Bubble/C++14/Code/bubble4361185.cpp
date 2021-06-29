#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int bubblesort(vector<int> &a){
    bool flag = 1;
    int n = a.size();
    int cnt = 0;
    while(flag){
        flag = 0;
        for(int i = n-1;i>=0;i--){
            if(a[i] < a[i-1]){
                swap(a[i],a[i-1]);
                cnt++;
                flag = 1;
            }
        }   
    }
    return cnt;
}

//ミョ(-ω- ?)
int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    rep(i,n)cin >> a.at(i);
    int res = bubblesort(a);
    rep(i,n) cout << (i ? " " : "") << a[i];
    cout << "\n" << res << endl;
    return 0;
}
