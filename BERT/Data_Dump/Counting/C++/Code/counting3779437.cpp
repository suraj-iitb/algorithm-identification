#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n + 1);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> C(100001);
    for (int i = 0; i < n; i++)
        C[A[i]]++;
    for (int i = 1; i <= 100001; i++)
        C[i] += C[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
