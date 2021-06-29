#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

void trace(vector<int> A) {
    rep(i, A.size()) {
        if (i > 0) cout << " ";
        cout << A.at(i);
    }
    cout << endl;
}

void insertionSort(vector<int> A) {
    int j, v;
    int N = A.size();

    rep2(i, 1, A.size()) {
        v = A.at(i);
        j = i - 1;
        while (j >= 0 && A.at(j) > v) {
            A.at(j + 1) = A.at(j);
            j--;
        }
        A.at(j + 1) = v;
        trace(A);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A.at(i);

    trace(A);
    insertionSort(A);

    return 0;
}
