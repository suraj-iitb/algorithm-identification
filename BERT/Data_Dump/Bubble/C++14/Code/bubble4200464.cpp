#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int bubble_sort(int A[], int n) {
    int sw = 0;
    bool flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = n - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                ++sw;
            }
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
    ans = bubble_sort(A, n);
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
