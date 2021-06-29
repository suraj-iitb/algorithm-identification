#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> ar(n);
    rep(i,n){
        cin >> ar[i];
    }
    int le, ri;
    bool t = true;
    int cnt = 0;
    while (t){
        t = false;
        rep(i,n-1){
            if (ar[i] > ar[i+1]){
                le = ar[i+1];
                ri = ar[i];
                ar[i] = le;
                ar[i+1] = ri;
                cnt++;
                t = true;
            }
        }
    }
    rep(j,n-1){
        cout << ar[j] << " ";
    }
    cout << ar[n-1] << endl;
    cout << cnt << endl;
}
