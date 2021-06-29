#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, n) for (int i = (a); i < (n); i++)
#define repb(i, n) for (int i = (n - 1); i >= 0; i--)
#define repb2(i, a, n) for (int i = (n - 1); i >= (a); i--)
#define all(x) x.begin(), x.end()
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
inline void fastio() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
const int INF = 2e9 + 7;

struct arr {
    int x, y, h;
};

void coelem(vector<int> &A, int N) {
    rep(i, N) {
        if (i < N - 1) {
            cosp(A[i]);
        } else {
            co(A[i]);
        }
    }
}

void insertionSort(vector<int> &A, int N) {
    rep2(i, 0, N) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        coelem(A, N);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    insertionSort(A, N);
    return 0;
}
