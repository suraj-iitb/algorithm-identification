#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
const ll INF64 = 1LL<<62;

int selectionSort(vector<int> &a, int n){
    int ret = 0;
    rep(i,n){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            swap(a[i], a[minj]);
            ret++;
        }
    }

    return ret;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = selectionSort(a, n);
    rep(i,n){
        cout << a[i];
        if(i!=n-1) cout << " ";
        else cout << endl;
    }
    cout << ans << endl;
}
