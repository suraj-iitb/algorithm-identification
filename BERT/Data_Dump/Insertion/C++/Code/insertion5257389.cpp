#include <bits/stdc++.h>
using namespace std;

void trace(vector<int>& A) {
    for(int i = 0; i < A.size(); i++) {
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(vector<int>& A) {
    trace(A);
    for (int i = 1; i < A.size(); i++) {
        int v = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > v)) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A);
    }
    return;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    insertionSort(A);
    return 0;
}
