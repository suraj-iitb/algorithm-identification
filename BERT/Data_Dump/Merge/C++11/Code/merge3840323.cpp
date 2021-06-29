
#include <bits/stdc++.h>

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

using namespace std;

typedef long long LL;

LL INF = 1 << 30;  // (2^10)^3 > 10^9

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

int merge(int*A, int left, int mid, int right) {
    int cmp = 0;

    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];

    REP(i, n1) L[i] = A[left + i];
    REP(i, n2) R[i] = A[mid + i];

    L[n1] = INF; R[n2] = INF; // sentinel

    int i = 0, j = 0;

    FOR(k, left, right) {
        if(L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }

        ++cmp;
    }

    return cmp;
}

int mergeSort(int* A, int left, int right) {
    int cmp = 0;

    if ((left + 1) < right) {
        int mid = (right + left) / 2;
        cmp += mergeSort(A, left, mid);
        cmp += mergeSort(A, mid, right);
        cmp += merge(A, left, mid, right);
    }

    return cmp;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int S[n];
    REP(i, n) cin >> S[i];

    int cmp = 0;
    cmp = mergeSort(S, 0, n);

    print(S, n);

    cout << cmp << endl;
}

