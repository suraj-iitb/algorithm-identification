
#include <bits/stdc++.h>

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

using namespace std;

typedef long long LL;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "[ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "]";

    return os;
}

void print(int* A, int n) {
    REP(i, n) {
        if (i > 0) cout << " ";

        cout << A[i];
    }
    cout << endl;
}

void coutingSort(int* A, int* B, int n, int k=10000) {
    int C[k];
    REP(i, k) C[i] = 0;

    REP(i, n) {
        ++C[A[i]];
    }

    FOR(i, 1, k) {
        C[i] += C[i - 1];
    }

    REP(i, n) {
        B[--C[A[i]]] = A[i];
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    int A[n];
    REP(i, n) cin >> A[i];

    int B[n];

    coutingSort(A, B, n);

    print(B, n);
}

