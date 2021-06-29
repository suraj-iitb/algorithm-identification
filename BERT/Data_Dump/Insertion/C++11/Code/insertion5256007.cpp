#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void trace(vector<int> a, int n){
    rep(i,n){
        if(i > 0) cout << " " << a[i];
        else cout << a[i];
    }
    cout << endl;
}

void insertionSort(vector<int> a, int n){
    for(int i = 1; i < n; ++i){
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a, n);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    trace(a, n);
    insertionSort(a, n);
    return 0;
}
