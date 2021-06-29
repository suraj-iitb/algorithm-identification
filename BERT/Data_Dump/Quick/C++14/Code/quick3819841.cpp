#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
const long long inf = 1LL << 60;
const int intinf = 1 << 30;
const long long mod = 1e9 + 7;

int n;

class TRUMP {
  public:
    char M;
    int N;
    TRUMP() {
        M = 'N';
        N = 0;
    }
    TRUMP(char mark, int number) {
        M = mark;
        N = number;
    }
};

template <class T> void vecout(T V) {
    auto t = V.begin();
    while(t != V.end()) {
        cout << *t++;
        if(t != V.end())
            cout << " ";
    }
    cout << endl;
};

int partition(vector<TRUMP> &A, int p, int r) {
    TRUMP tmp;
    int x = A[r].N;
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(A[j].N <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);

    return i + 1;
}

void merge(vector<TRUMP> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<TRUMP> L(n1 + 1);
    vector<TRUMP> R(n2 + 1);
    rep(i, n1) L[i] = A[left + i];
    L[n1].N = intinf;
    rep(i, n2) R[i] = A[mid + i];
    R[n2].N = intinf;
    int i = 0, j = 0;
    rep(k, left, right) {
        if(L[i].N <= R[j].N) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(vector<TRUMP> &A, int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void QuickSort(vector<TRUMP> &A, int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}
int main() {
    cin >> n;
    vector<TRUMP> A(n), B(n);
    rep(i, n) {
        cin >> A[i].M >> A[i].N;
        B[i] = A[i];
    }

    QuickSort(A, 0, n - 1);
    MergeSort(B, 0, n);

    bool St = true;
    rep(i, n) {
        if(A[i].M != B[i].M)
            St = false;
    }
    cout << (St ? "S" : "Not s") << "table\n";
    rep(i, n) { cout << A[i].M << " " << A[i].N << "\n"; }
}

