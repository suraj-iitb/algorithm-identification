#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int n;
vector<int> A;

void insertionSort(int n) {
    REP(i, n) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        REP(k, n - 1) cout << A[k] << " ";
        cout << A[n - 1] << endl;
    }
}

int main() {
    cin >> n;
    REP(i, n) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    insertionSort(n);
    return 0;
}
