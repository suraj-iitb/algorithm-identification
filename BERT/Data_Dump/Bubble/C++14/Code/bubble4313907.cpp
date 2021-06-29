#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A.at(i);
    }

    bool flag = true;
    int i = 0;
    int count = 0;
    while (flag) {
        flag = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (A.at(j - 1) > A.at(j)) {
                swap(A.at(j - 1), A.at(j));
                count++;
                flag = true;
            }
        }
        i++;
    }

    for (int k = 0; k < n; k++) {
        cout << A.at(k);
        if (k != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}
