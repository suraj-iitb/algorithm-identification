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

int selSort(vi &A) {
    int n = 0;
    REP(i, SZ(A)) {
        int minj = i;
        FOR(j, i, SZ(A)) if (A[j] < A[minj]) minj = j;
        if (i != minj) {
            n++;
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;}}
    return n;
}

int main(){
    int n; cin >> n;
    vi A(n); REP(i,n) cin >> A[i];
    int nu = selSort(A);
    REP(i,n) {
        cout << A[i];
        i == n-1 ? cout << endl : cout << " ";}
    cout << nu << endl;
}
