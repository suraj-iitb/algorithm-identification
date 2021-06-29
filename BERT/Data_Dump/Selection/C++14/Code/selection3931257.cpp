#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define repb(i, a, n) for (int i = (a); i >= (n); i--)
#define all(x) x.begin(), x.end()
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
inline void fastio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

void co_elem(vector<int> &A) {
    rep(i, 0, A.size() - 1) {
        if (i < A.size() - 1) {
            cosp(A[i]);
        } else {
            co(A[i]);
        }
    }
}

void bubbleSort(vector<int> &A, int N, int &changed) {
    int flag = 1;
    int i = 0;
    while (flag) {
        flag = 0;
        repb(j, N - 1, i + 1) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                changed++;
            }
        }
        i++;
    }
}

void selectionSort(vector<int> &A, int N, int &changed) {
    rep(i, 0, N - 1) {
        int minv = A[i], tmp = 0;
        rep(j, i + 1, N - 1) {
            if (A[j] < minv) {
                minv = A[j];
                tmp = j;
            }
        }
        if (A[i] != minv) {
            swap(A[i], A[tmp]);
            changed++;
        }
    }
}

int main() {
    int N, changed = 0;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N - 1) {
        cin >> A[i];
    }
    selectionSort(A, N, changed);
    co_elem(A);
    co(changed);
    return 0;
}
