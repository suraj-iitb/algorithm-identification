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
    rep(i, n) {
        int minj = i;
        REP(j, i, n) {
            if(a[j] < a[minj]) {
                minj = j;
            }
        }
        swap(a[i], a[minj]);
        if(i != minj) {
            res++;
        }
    }
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl << res << endl;
}

