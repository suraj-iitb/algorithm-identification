/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
          fozubaoyou    no BUGs alive
*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define RFOR(i, a, b) for(int i = b; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef vector<int> vi;

int bubSort(vi &A) {
    bool flg = true;
    int n = 0;
    while (flg) {
        flg = false;
        RFOR(i, 1, SZ(A)-1) {
            if (A[i] < A[i-1]) {
                int tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flg = true;
                n++;}}}
    return n;
}

int main(){
    int n; cin >> n;
    vi A(n); REP(i,n) cin >> A[i];
    int nu = bubSort(A);
    REP(i,n) {
        cout << A[i];
        i == n-1 ? cout << endl : cout << " ";}
    cout << nu << endl;
}
