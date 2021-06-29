#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int selectionsort(vector<int> &a){
    int cnt = 0;
    rep(i,a.size()){
        int minj = i;
        for(int j = i;j<a.size();j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj)cnt++;
        swap(a[i],a[minj]);
    }
    return cnt;
}

//ミョ(-ω- ?)
int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    rep(i,n)cin >> a.at(i);
    int res = selectionsort(a);
    rep(i,n) cout << (i ? " " : "") << a[i];
    cout << "\n" << res << endl;
    return 0;
}
