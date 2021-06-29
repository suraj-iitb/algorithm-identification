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

int selection_sort(int a[], int n) {
    int cnt = 0;
    for(int i=0; i < n; ++i) {
        int minj = i;
        for(int j=i; j < n; ++j) {
            if(a[minj] > a[j]) {
                minj = j;
            }
        }
        swap(a[i], a[minj]);
        if(i != minj) ++cnt;
    }
    return cnt;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    int n; cin >> n;
    rep(i,n) cin >> A[i];

    int cnt = selection_sort(A,n);

    rep(i,n) {
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl << cnt << endl;

    return 0;
}

