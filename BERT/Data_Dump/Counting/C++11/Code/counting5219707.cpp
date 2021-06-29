#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int k = *max_element(A.begin(), A.end()) + 1;
    vector<int> C(k);
    for (int x: A) C[x]++;
    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    vector<int> B(n);
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}
