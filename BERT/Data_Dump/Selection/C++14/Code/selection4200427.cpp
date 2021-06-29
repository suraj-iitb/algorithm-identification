#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int selection_sort(int A[], int n) {
    int minj, sw = 0;
    rep(i, n) {
        minj = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(A[i], A[minj]);
            ++sw;
        }
    }
    return sw;
}

void Main() {
    int n;
    cin >> n;
    int A[100];
    rep(i, n) cin >> A[i];
    int ans;
    ans = selection_sort(A, n);
    rep(i, n) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n" << ans << "\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
