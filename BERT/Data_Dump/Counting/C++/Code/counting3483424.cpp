#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) REPN(i,0,n)
#define REPN(i,m,n) for(int i=m; i<(n); i++)

#define MAX 2000001
#define VMAX 10000

int main() {
    int n, i, j;
    cin >> n;

    int A[n+1], B[n+1], C[VMAX+1];
    REP(i, VMAX+1) {
        C[i] = 0;
    }

    REP(i, n) {
        cin >> A[i+1];
        C[A[i+1]]++;
    }

    REPN(i, 1, VMAX+1) {
        C[i] = C[i] + C[i-1];
    }

    REPN(j, 1, n+1) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    REPN(i, 1, n+1) {
        if (i > 1) {
            cout << " ";
        }
        cout << B[i];
    }
    cout << '\n';
}
