#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;



int main() {
    int n; cin >> n;int a[n];for(int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    for(int i = 0;i < n;i++){
        int j = n - 1;
        while(i <= j){
            if(a[j-1] > a[j]){
                ans++;
                swap(a[j-1],a[j]);
            }
            j--;
        }
    }
    for(int i = 0;i < n;i++){
        if(i < n-1){
            cout << a[i] << " ";
        }else{
            cout << a[i] << endl;
        }
    }
    cout << ans << endl;
}


