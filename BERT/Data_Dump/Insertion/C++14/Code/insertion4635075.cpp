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

void insertionSort(vector<int> a,int n){

    rep(i,n){
        cout << a[i];
        if(i < n - 1){
            cout << " ";
        }
    }
    cout << endl;

    for(int i = 1; i < n; i++){
        int v = a[i];

        int j = i - 1;
        
        while(j >= 0 && v < a[j]){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = v;

        rep(i,n){
            cout << a[i];
            if(i < n - 1){
                 cout << " ";
            }           
        }
        cout << endl;
    }


}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    insertionSort(a,n);


}
