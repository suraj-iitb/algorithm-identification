#include <bits/stdc++.h>
using namespace std;

void doc(){
    freopen("OB.inp","r", stdin);
    freopen("OB.out","w", stdout);
}

void solve(){
    int n;
    cin >> n;
    int a[n], m = 0;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        m = max(m, a[i]);
    }
    int d[m + 1];
    memset(d, 0, sizeof(d));
    for(int i = 0; i < n; i++) d[a[i]]++;
    for(int i = 0; i < m; i++)
        while (d[i]--) cout << i << " ";
    for(int i = 1; i < d[m]; i++)
        cout << m << " ";
    cout << m << '\n';
}

int main(){
   // ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
   // doc();
    solve();
}

