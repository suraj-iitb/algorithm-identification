#include <bits/stdc++.h>
using namespace std;

void printA(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(vector<int> &A) {
    printA(A);
    for (int i = 1; i < A.size(); i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printA(A);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    insertionSort(A);

    return 0;
}

