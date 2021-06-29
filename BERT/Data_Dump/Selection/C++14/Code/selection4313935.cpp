#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A.at(i);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (A.at(j) < A.at(minj)) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A.at(i), A.at(minj));
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << A.at(i);
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << count << endl;
}
