#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long ll;
// Welcome to my source code!

#define MAXV 10000

int main() {
    unsigned short *A, *B;
    int n, C[MAXV+1] = {};
    cin >> n;

    A = new short unsigned int[n+1];
    B = new short unsigned int[n+1];

    rep(i,n) {
        cin >> A[i+1];
        C[A[i+1]]++;
    }

    for (int i = 1; i <= MAXV; i++) C[i] += C[i-1];

    for (int j = 1; j <= n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << B[i];
    }
    cout << endl;
}
