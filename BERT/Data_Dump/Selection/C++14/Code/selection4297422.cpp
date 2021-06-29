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
    int cnt = 0;
    int mi;
    int e;
    int le, ri;
    rep(i,n-1){
        mi = ar[i];
        e = i;
        repp(j,n,i+1){
            if (mi > ar[j]){
                mi = ar[j];
                e = j;
            }
        }
        if (e != i){
            le = ar[e];
            ri = ar[i];
            ar[i] = le;
            ar[e] = ri;
            cnt++;
        }
    }
    rep(i,n-1){
        cout << ar[i] << " ";
    }
    cout << ar[n-1] << endl;
    cout << cnt << endl;
}
