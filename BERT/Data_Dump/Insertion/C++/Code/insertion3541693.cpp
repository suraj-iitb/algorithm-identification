//#include<bist_stdc++.h>
#include <iostream>
#include <vector>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl;
    REP(i, 1, n) {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        rep(i, n - 1) cout << a[i] << " ";
        cout << a[n - 1] << endl;
    }
}
