#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n+1);
    int k = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.at(i) = a;
        if (a > k) k = a;
    }
    vector<int> C(k+1);

    for (int i = 0; i < k+1; i++) {
        C.at(i) = 0;
    }
    for (int i = 0; i < n; i++) {
        C.at(A.at(i))++;
    }
    for (int i = 1; i < k+1; i++) {
        C.at(i) = C.at(i) + C.at(i-1);
    }

    for (int i = n-1; i >= 0; i--) {
        int a = A.at(i);
        int t = C.at(a);
        B.at(t) = a;
        C.at(a)--;
    }

    for (int i = 1; i < n+1; i++) {
        if (i != 1) cout << " ";
        cout << B.at(i);
    }
    cout << endl;

    return 0;
}
