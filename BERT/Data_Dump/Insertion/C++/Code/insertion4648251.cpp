#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v, j;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A.at(i);
    }

    for(int i = 0; i < n; i++) {
        cout << A.at(i);
        if(i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    for(int i = 1; i < n; i++) {
        v = A.at(i);
        j = i - 1;
        while(j >= 0 && A.at(j) > v) {
            A.at(j + 1) = A.at(j);
            j--;
        }
        A.at(j + 1) = v;

        for(int i = 0; i < n; i++) {
            cout << A.at(i);
            if(i == n - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}
