#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int bubbleSort(vector<int>&a, int n){
    bool flag = true;
    int cnt = 0;
    while(flag){
        flag = false;
        
        for(int i = n-1; i > 0; i--){
            if(a[i] < a[i-1]){
                swap(a[i],a[i-1]);
                cnt++;
                flag = true;
            }
        }


    }
    return cnt;

}



int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
    }

    int ans = bubbleSort(a,n);
    
    rep(i,n){
        cout << a[i];
        if(i < n - 1){
            cout << " ";
        }
    }
    cout << endl << ans << endl;





}
