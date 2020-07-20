#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define MOD 1000000007
#define endl "\n" 
#define rep(i,n) for(int i = 0; i < (n); ++i)
typedef long long ll;

int A[110];

int bubble_sort(int a[], int n) {
    bool flag = true;
    int cnt = 0;
    for(int i=0; flag; ++i) {
        flag = false;
        for(int j=n-1; j >= i+1; --j) {
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                flag = true;
                ++cnt;
            }
        }
    }
    return cnt;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    int n; cin >> n;
    rep(i,n) cin >> A[i];

    int cnt = bubble_sort(A,n);
    rep(i,n) {
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl << cnt << endl; 

    return 0;
}

