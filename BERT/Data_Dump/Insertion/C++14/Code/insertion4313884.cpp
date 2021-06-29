#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A.at(i);
        cout << A.at(i);
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        int v = A.at(i);
        int j = i - 1;
        while (j >= 0 && A.at(j) > v) {
            A.at(j + 1) = A.at(j);
            j--;
        }
        A.at(j + 1) = v;

        for (int k = 0; k < n; k++) {
            cout << A.at(k);
            if (k != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
