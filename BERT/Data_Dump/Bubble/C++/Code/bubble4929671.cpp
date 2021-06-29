#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;

int main(int argc, const char * argv[]) {
    int n, ans=0;
    cin >> n;
    
    vector<int> A(n);
    rep(i, n){
        cin >> A[i];
    }
    
    rep(i, n){
        for(int j=n-1; j>i; j--){
            if(A[j-1] > A[j]){
                swap(A[j-1], A[j]);
                ans++;
            }
        }
    }
    
    rep(i, n){
        if(i==n-1) cout << A[i] << endl;
        else cout << A[i] << ' ';
    }
    cout << ans <<  endl;
    
    return 0;
}

