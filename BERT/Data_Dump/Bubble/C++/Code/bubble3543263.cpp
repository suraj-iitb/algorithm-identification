//#include<bits_stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define ll long long
using namespace std;
int main() {
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool flg = true;
    while(flg) {
        flg = false;
        for(int i = n - 1; i > 0; i--) {
            if(a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                flg = true;
                res++;
            }
        }
    }
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl;
    cout << res << endl;
}
