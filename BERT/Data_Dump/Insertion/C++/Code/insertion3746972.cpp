#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> A, int N) {
    for (int i = 0; i < N; i++) {
        int v = A.at(i);
        int j = i-1;
        while (j >= 0 && A.at(j) > v) {
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
        for (int x = 0; x < N; x++) {
            if (x < N-1) {
                cout << A.at(x) << " ";
            } else {
                cout << A.at(x) << endl;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    insertionSort(A, N);

    return 0;
}

