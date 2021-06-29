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

void insert_sort(int a[], int n) {
    for(int i=1; i < n; ++i) {
        int v = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
        for(int k=0; k < n; ++k) {
            if(k > 0) cout << " ";
            cout << a[k];
        }
        cout << endl;
    } 
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
  
    int n; cin >> n;
    rep(i,n) cin >> A[i];

    rep(i,n) {
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    insert_sort(A, n);


    return 0;
}

