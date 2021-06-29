#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
const ll INF64 = 1LL<<62;

int bubbleSort(vector<int> &a, int n){
    int ret = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=n-1; j>=1; j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                ret++;
                flag = true;
            }
        }
    }

    return ret;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = bubbleSort(a, n);
    rep(i,n){
        cout << a[i];
        if(i!=n-1) cout << " ";
        else cout << endl;
    }
    cout << ans << endl;
}
