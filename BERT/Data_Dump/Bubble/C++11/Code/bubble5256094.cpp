#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int bubbleSort(vector<int> &a, int n){
    int ans = 0;
    bool flg = 1;
    for(int i = 0; flg; i++){ // iで未ソートの先頭を示す
        flg = 0;
        for(int j = n-1; j > i; --j){ // 未ソートの先頭まで探索
            if(a[j] < a[j-1]){
                // 隣接要素を交換
                swap(a[j], a[j-1]);
                flg = 1;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = bubbleSort(a, n);
    rep(i,n){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}
