#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF = 2e9
#define LINF = 1e18
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO")
#define Yes(n) cout << ((n) ? "Yes" : "No")

int main(){

    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n)cin >> a[i];
    for(int j = 0; j < n-1; j++){
        cout << a[j] << " ";
    }
    cout << a[n-1] << endl;

    for(int i = 1; i < n; i++){

        int v = a[i];

        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = v;

        for(int j = 0; j < n-1; j++){
            cout << a[j] << " ";
        }
        cout << a[n-1] << endl;

    }

}
